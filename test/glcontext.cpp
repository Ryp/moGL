#include <iostream>
#include <stdexcept>

#include "glcontext.hpp"

GLContext::GLContext()
:   _window(nullptr),
    _windowSize({0, 0})
{}

GLContext::~GLContext() {}

void GLContext::create(int width, int height, bool fullscreen)
{
    if (!glfwInit())
        throw (std::runtime_error("Failed to initialize GLFW"));
    GLFWmonitor* monitor;
    if (!(monitor = glfwGetPrimaryMonitor()))
        throw (std::runtime_error("Failed to retrieve primary monitor"));
    if (!(_window = glfwCreateWindow(width, height, "GLContext", ((fullscreen) ? (monitor) : (nullptr)), nullptr)))
    {
        destroy();
        throw (std::runtime_error("Failed to open GLFW window"));
    }
    _windowSize = {800, 600};
    glfwMakeContextCurrent(_window);

    // FIXME Needed for core profile (may generate GLenum error)
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
        throw (std::runtime_error("Failed to initialize GLEW"));
    glfwSwapInterval(1); // NOTE Drivers may ignore this
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

bool GLContext::isOpen()
{
    return (!glfwWindowShouldClose(_window));
}

void GLContext::swapBuffers()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void GLContext::destroy()
{
    if (_window)
        glfwDestroyWindow(_window);
    glfwTerminate();
}

const Vect2u& GLContext::getWindowSize() const
{
    return (_windowSize);
}

double GLContext::getTime() const
{
    return (glfwGetTime());
}

Vect2u GLContext::getCursorPosition() const
{
    double v[2];
    Vect2u    ret;
    glfwGetCursorPos(_window, &(v[0]), &(v[1]));

    ret.x = static_cast<unsigned int>(v[0]);
    ret.y = static_cast<unsigned int>(v[1]);
    return (ret);
}

void GLContext::setCursorPosition(const Vect2u& position)
{
    glfwSetCursorPos(_window, position.x, position.y);
}

void GLContext::centerCursor()
{
    Vect2u    ret = _windowSize;

    ret.x /= 2;
    ret.y /= 2;
    setCursorPosition(ret);
}

void GLContext::setTitle(const std::string& title)
{
    glfwSetWindowTitle(_window, title.c_str());
}

void GLContext::printLog(bool full)
{
    GLint major, minor;
    GLint nExtensions;

    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    glGetIntegerv(GL_NUM_EXTENSIONS, &nExtensions);
    std::clog << "########## ContextLog ##########" << std::endl;
    std::clog << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::clog << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::clog << "Version string: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::clog << "Version number: " << major << "." << minor << std::endl;
    if (full)
    {
        std::clog << "OpenGL extensions supported:" << std::endl;
        for (int i = 0; i < nExtensions; ++i)
            std::clog << glGetStringi(GL_EXTENSIONS, i) << std::endl;
    }
    std::clog << "################################" << std::endl;
}

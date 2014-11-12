#include <iostream>
#include <stdexcept>

#include <glbinding/gl/gl.h>
#include <glbinding/ContextInfo.h>
#include <glbinding/Version.h>
#include <glbinding/Binding.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

using namespace gl;
using namespace glbinding;

#include "glcontext.hpp"

GLContext::GLContext()
:   _window(nullptr),
    _windowSize({0, 0})
{}

void GLContext::create(unsigned int width, unsigned int height, bool fullscreen)
{
    if (!glfwInit())
        throw (std::runtime_error("Failed to initialize GLFW"));
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
//     glfwWindowHint(GLFW_RESIZABLE, 0);
    GLFWmonitor* monitor;
    if (!(monitor = glfwGetPrimaryMonitor()))
        throw (std::runtime_error("Failed to retrieve primary monitor"));
    if (!(_window = glfwCreateWindow(width, height, "GLContext", ((fullscreen) ? (monitor) : (nullptr)), nullptr)))
    {
        destroy();
        throw (std::runtime_error("Failed to open GLFW window"));
    }
    _windowSize = {width, height};
    glfwMakeContextCurrent(_window);

    Binding::initialize();
    std::cout << std::endl
    << "OpenGL Version:  " << ContextInfo::version() << std::endl
    << "OpenGL Vendor:   " << ContextInfo::vendor() << std::endl
    << "OpenGL Renderer: " << ContextInfo::renderer() << std::endl;

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
    GLint   major, minor;
    GLint   nExtensions;

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
        for (GLint i = 0; i < nExtensions; ++i)
            std::clog << glGetStringi(GL_EXTENSIONS, static_cast<GLuint>(i)) << std::endl;
    }
    std::clog << "################################" << std::endl;
}

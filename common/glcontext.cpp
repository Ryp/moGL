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

void GLContext::create(unsigned int width, unsigned int height, unsigned int major, unsigned int minor, bool fullscreen, bool debug)
{
    if (!glfwInit())
        throw (std::runtime_error("Failed to initialize GLFW"));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (debug)
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
    glfwWindowHint(GLFW_RESIZABLE, 0);
    glfwSetErrorCallback([] (int e, const char* str) { std::cout << "GLFW Context error (" << e << "): " << str << std::endl; });
    GLFWmonitor* monitor;
    if (!(monitor = glfwGetPrimaryMonitor()))
        throw (std::runtime_error("Failed to retrieve primary monitor"));
    if (!(_window = glfwCreateWindow(width, height, "GLContext", ((fullscreen) ? (monitor) : (nullptr)), nullptr)))
    {
        destroy();
        throw (std::runtime_error("Failed to open GLFW window"));
    }
    _windowSize = {width, height};
    makeCurrent();

    Binding::initialize(true);

    glfwSwapInterval(1); // NOTE Drivers may ignore this
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

bool GLContext::isOpen()
{
    return !glfwWindowShouldClose(_window);
}

void GLContext::swapBuffers()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void GLContext::makeCurrent()
{
    glfwMakeContextCurrent(_window);
}

void GLContext::destroy()
{
    if (_window)
        glfwDestroyWindow(_window);
    glfwTerminate();
}

const Vect2u& GLContext::getWindowSize() const
{
    return _windowSize;
}

double GLContext::getTime() const
{
    return glfwGetTime();
}

Vect2u GLContext::getCursorPosition() const
{
    double  v[2];

    glfwGetCursorPos(_window, &(v[0]), &(v[1]));
    return Vect2u{static_cast<unsigned int>(v[0]), static_cast<unsigned int>(v[1])};
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

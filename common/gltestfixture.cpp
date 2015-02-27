////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file gltestfixture.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "gltestfixture.hpp"

#include <glbinding/gl/gl.h>

using namespace gl;

static void debugCallback(GLenum /*source*/, GLenum type, GLuint id, GLenum severity,
                          GLsizei /*length*/, const GLchar *message, const void */*userParam*/)
{
    std::cout << "DEBUG message: "<< message << " type: ";
    switch (type) {
        case GL_DEBUG_TYPE_ERROR:               std::cout << "ERROR"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "DEPRECATED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "UNDEFINED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "PORTABILITY"; break;
        case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "PERFORMANCE"; break;
        case GL_DEBUG_TYPE_OTHER:               std::cout << "OTHER"; break;
        default:
            break;
    }
    std::cout << " id: " << id << " severity: ";
    switch (severity){
        case GL_DEBUG_SEVERITY_LOW:     std::cout << "LOW"; break;
        case GL_DEBUG_SEVERITY_MEDIUM:  std::cout << "MEDIUM"; break;
        case GL_DEBUG_SEVERITY_HIGH:    std::cout << "HIGH"; break;
        default:
            break;
    }
    std::cout << std::endl;
}

void GLTestFixture::SetUp()
{
    _ctx.create(800, 600, 4, 5, false, true);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugCallback, nullptr);
    GLuint unusedIds = 0;
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, &unusedIds, GL_TRUE);
};

void GLTestFixture::TearDown()
{
    _ctx.destroy();
};

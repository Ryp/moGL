////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file debug.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "glcontext.hpp" // First to be included
#include <GL/gl.h>

#include <iostream>
#include <mogl/debug.hpp>

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);
    {
        // Valid enum test
        try {
            glActiveTexture(GL_TEXTURE0); MOGL_ASSERT();
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return (1); // Assert should not throw
        }

        // Invalid enum test
        try {
            glActiveTexture(GL_COLOR); MOGL_ASSERT();
            return (2); // Assert did not throw
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
    ctx.destroy();
    return (0);
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "glcontext.hpp" // First to be included
#include <GL/gl.h>

#include <mogl/framebuffer/framebufferobject.hpp>

using mogl::FrameBufferObject;

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);

    FrameBufferObject   fbo;

    fbo.bind(FrameBufferObject::Target::DrawFrameBuffer);
    fbo.destroy();

    ctx.destroy();
    return (0);
}

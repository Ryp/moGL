////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

using mogl::FrameBufferObject;

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);
    {
        FrameBufferObject   fbo;

        fbo.bind(mogl::FrameBuffer::Target::DrawFrameBuffer);
    }
    ctx.destroy();
    return (0);
}

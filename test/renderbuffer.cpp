////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

using mogl::RenderBufferObject;

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);
    {
        RenderBufferObject   dbo;
        dbo.bind();
        dbo.getHandle();
    }
    ctx.destroy();
    return (0);
}

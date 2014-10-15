////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferfunctions.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED
#define MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED

#include <mogl/renderbuffer/renderbufferobject.hpp>

namespace mogl
{
    namespace FrameBuffer
    {
        enum class Target {
            DrawFrameBuffer = GL_DRAW_FRAMEBUFFER,
            ReadFrameBuffer = GL_READ_FRAMEBUFFER,
            FrameBuffer = GL_FRAMEBUFFER
        };
        enum class Attachment {
            Color0 = GL_COLOR_ATTACHMENT0,
            Depth = GL_DEPTH_ATTACHMENT,
            Stencil = GL_STENCIL_ATTACHMENT
        };

        static bool isComplete(Target target);
        static void setRenderBuffer(Target target, Attachment attachment, const RenderBufferObject& renderbuffer);
        static void setTexture2D(Target target, Attachment attachment, GLenum textarget, GLuint texture, GLint level);
    };
}

#include "framebufferfunctions.inl"

#endif // MOGL_FRAMEBUFFERFUNCTIONS_INCLUDED

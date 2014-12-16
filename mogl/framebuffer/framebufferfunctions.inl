////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferfunctions.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "framebufferfunctions.hpp"
#include "mogl/debug.hpp"

namespace mogl
{
    inline bool FrameBuffer::isComplete(Target target)
    {
        GLenum rslt = glCheckFramebufferStatus(static_cast<GLenum>(target)); MOGL_GL_CALL();
        return (rslt == GL_FRAMEBUFFER_COMPLETE);
    }

    inline void FrameBuffer::setRenderBuffer(Target target, Attachment attachment, const RenderBufferObject& renderbuffer)
    {
        glFramebufferRenderbuffer(static_cast<GLenum>(target),
                                  static_cast<GLenum>(attachment),
                                  static_cast<GLenum>(RenderBufferObject::Target::RenderBuffer),
                                  renderbuffer.getHandle()
        ); MOGL_GL_CALL();
    }

    inline void FrameBuffer::setTexture2D(Target target, Attachment attachment, mogl::TextureObject& texture, GLint level)
    {
        glFramebufferTexture2D(static_cast<GLenum>(target),
                               static_cast<GLenum>(attachment),
                               texture.getTarget(),
                               texture.getHandle(),
                               level
        ); MOGL_GL_CALL();
    }
}

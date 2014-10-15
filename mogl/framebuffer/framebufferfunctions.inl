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

namespace mogl { namespace FrameBuffer
{
    bool isComplete(Target target)
    {
        return (glCheckFramebufferStatus(static_cast<GLenum>(target)) == GL_FRAMEBUFFER_COMPLETE);
    }

    void setRenderBuffer(Target target, Attachment attachment, const RenderBufferObject& renderbuffer)
    {
        glFramebufferRenderbuffer(static_cast<GLenum>(target),
                                  static_cast<GLenum>(attachment),
                                  static_cast<GLenum>(RenderBufferObject::Target::RenderBuffer),
                                  renderbuffer.getHandle()
                                 );
    }

    void setTexture2D(Target target, Attachment attachment, GLenum textarget, GLuint texture, GLint level)
    {
        glFramebufferTexture2D(static_cast<GLenum>(target),
                               static_cast<GLenum>(attachment),
                               textarget,
                               texture,
                               level
                              );
    }
}}

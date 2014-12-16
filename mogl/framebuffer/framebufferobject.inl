////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "framebufferobject.hpp"
#include "mogl/debug.hpp"

namespace mogl
{
    inline FrameBufferObject::FrameBufferObject()
    :   _handle(0)
    {
        glGenFramebuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline FrameBufferObject::~FrameBufferObject()
    {
        glDeleteFramebuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline void FrameBufferObject::bind(FrameBuffer::Target target)
    {
        glBindFramebuffer(static_cast<GLenum>(target), _handle); MOGL_GL_CALL();
    }

    inline void FrameBufferObject::setRenderBuffer(FrameBuffer::Attachment attachment, const RenderBufferObject& renderbuffer)
    {
        glNamedFramebufferRenderbuffer(_handle,
                                       static_cast<GLenum>(attachment),
                                       static_cast<GLenum>(RenderBufferObject::Target::RenderBuffer),
                                       renderbuffer.getHandle()
        ); MOGL_GL_CALL();
    }

    inline GLuint FrameBufferObject::getHandle() const
    {
        return (_handle);
    }
}

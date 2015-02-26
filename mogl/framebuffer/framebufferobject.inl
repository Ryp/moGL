////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline FrameBufferObject::FrameBufferObject()
    {
        glCreateFramebuffers(1, &_handle);
    }

    inline FrameBufferObject::~FrameBufferObject()
    {
        if (_handle)
            glDeleteFramebuffers(1, &_handle);
    }

    inline void FrameBufferObject::bind(GLenum target)
    {
        glBindFramebuffer(target, _handle);
    }

    inline void FrameBufferObject::setRenderBuffer(GLenum attachment, RenderBufferObject& renderbuffer)
    {
        glNamedFramebufferRenderbuffer(_handle, attachment, GL_RENDERBUFFER, renderbuffer.getHandle());
    }

    inline void FrameBufferObject::setTexture(GLenum attachment, TextureObject& texture, GLint level)
    {
        glNamedFramebufferTexture(_handle, attachment, texture.getHandle(), level);
    }

    inline void FrameBufferObject::setDrawBuffer(GLenum buffer)
    {
        glNamedFramebufferDrawBuffer(_handle, buffer);
    }

    inline void FrameBufferObject::setDrawBuffers(GLsizei size, const GLenum* buffers)
    {
        glNamedFramebufferDrawBuffers(_handle, size, buffers);
    }

    inline void FrameBufferObject::set(GLenum property, GLint value)
    {
        glNamedFramebufferParameteri(_handle, property, value);
    }

    inline bool FrameBufferObject::isComplete(GLenum target)
    {
        return glCheckNamedFramebufferStatus(_handle, target) == GL_FRAMEBUFFER_COMPLETE;
    }

    inline bool FrameBufferObject::isValid() const
    {
        return glIsFramebuffer(_handle) == GL_TRUE;
    }

    template <>
    inline void FrameBufferObject::clear<GLint>(GLenum buffer, GLint drawbuffer, const GLint* value)
    {
        glClearNamedFramebufferiv(_handle, buffer, drawbuffer, value);
    }

    template <>
    inline void FrameBufferObject::clear<GLuint>(GLenum buffer, GLint drawbuffer, const GLuint* value)
    {
        glClearNamedFramebufferuiv(_handle, buffer, drawbuffer, value);
    }

    template <>
    inline void FrameBufferObject::clear<GLfloat>(GLenum buffer, GLint drawbuffer, const GLfloat* value)
    {
        glClearNamedFramebufferfv(_handle, buffer, drawbuffer, value);
    }

    inline void FrameBufferObject::clear(GLenum buffer, GLfloat depth, GLint stencil)
    {
        glClearNamedFramebufferfi(_handle, buffer, depth, stencil);
    }
}

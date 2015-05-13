////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline FrameBuffer::FrameBuffer()
    :   Handle(GL_FRAMEBUFFER)
    {
        glCreateFramebuffers(1, &_handle);
    }

    inline FrameBuffer::~FrameBuffer()
    {
        if (_handle)
            glDeleteFramebuffers(1, &_handle);
    }

    inline void FrameBuffer::bind(GLenum target)
    {
        glBindFramebuffer(target, _handle);
    }

    inline void FrameBuffer::setRenderBuffer(GLenum attachment, RenderBuffer& renderbuffer)
    {
        glNamedFramebufferRenderbuffer(_handle, attachment, GL_RENDERBUFFER, renderbuffer.getHandle());
    }

    inline void FrameBuffer::setTexture(GLenum attachment, Texture& texture, GLint level)
    {
        glNamedFramebufferTexture(_handle, attachment, texture.getHandle(), level);
    }

    inline void FrameBuffer::setDrawBuffer(GLenum buffer)
    {
        glNamedFramebufferDrawBuffer(_handle, buffer);
    }

    inline void FrameBuffer::setDrawBuffers(GLsizei size, const GLenum* buffers)
    {
        glNamedFramebufferDrawBuffers(_handle, size, buffers);
    }

    inline void FrameBuffer::invalidate(GLsizei numAttachments, const GLenum* attachments)
    {
        glInvalidateNamedFramebufferData(_handle, numAttachments, attachments);
    }

    inline void FrameBuffer::invalidateSubData(GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glInvalidateNamedFramebufferSubData(_handle, numAttachments, attachments, x, y, width, height);
    }

    inline void FrameBuffer::set(GLenum property, GLint value)
    {
        glNamedFramebufferParameteri(_handle, property, value);
    }

    inline bool FrameBuffer::isComplete(GLenum target)
    {
        return glCheckNamedFramebufferStatus(_handle, target) == GL_FRAMEBUFFER_COMPLETE;
    }

    inline bool FrameBuffer::isValid() const
    {
        return glIsFramebuffer(_handle) == GL_TRUE;
    }

    template <>
    inline void FrameBuffer::clear<GLint>(GLenum buffer, GLint drawbuffer, const GLint* value)
    {
        glClearNamedFramebufferiv(_handle, buffer, drawbuffer, value);
    }

    template <>
    inline void FrameBuffer::clear<GLuint>(GLenum buffer, GLint drawbuffer, const GLuint* value)
    {
        glClearNamedFramebufferuiv(_handle, buffer, drawbuffer, value);
    }

    template <>
    inline void FrameBuffer::clear<GLfloat>(GLenum buffer, GLint drawbuffer, const GLfloat* value)
    {
        glClearNamedFramebufferfv(_handle, buffer, drawbuffer, value);
    }

    inline void FrameBuffer::clear(GLenum buffer, GLfloat depth, GLint stencil)
    {
        glClearNamedFramebufferfi(_handle, buffer, depth, stencil);
    }
}

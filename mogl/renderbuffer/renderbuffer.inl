////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbuffer.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline RenderBuffer::RenderBuffer()
    {
        glCreateRenderbuffers(1, &_handle);
    }

    inline RenderBuffer::~RenderBuffer()
    {
        if (_handle)
            glDeleteRenderbuffers(1, &_handle);
    }

    inline void RenderBuffer::setStorage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorage(_handle, internalformat, width, height);
    }

    inline void RenderBuffer::setStorageMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorageMultisample(_handle, samples, internalformat, width, height);
    }

    inline void RenderBuffer::getParameteriv(GLenum property, GLint* value)
    {
        glGetNamedRenderbufferParameteriv(_handle, property, value);
    }

    inline bool RenderBuffer::isValid() const
    {
        return glIsRenderbuffer(_handle) == GL_TRUE;
    }
}

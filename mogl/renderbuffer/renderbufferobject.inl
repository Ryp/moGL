////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "renderbufferobject.hpp"

namespace mogl
{
    inline RenderBufferObject::RenderBufferObject()
    {
        glCreateRenderbuffers(1, &_handle);
    }

    inline RenderBufferObject::~RenderBufferObject()
    {
        glDeleteRenderbuffers(1, &_handle);
    }

    inline bool RenderBufferObject::isValid() const
    {
        return glIsRenderbuffer(_handle) == GL_TRUE;
    }

    inline void RenderBufferObject::setStorage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorage(_handle, internalformat, width, height);
    }

    inline void RenderBufferObject::setStorageMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorageMultisample(_handle, samples, internalformat, width, height);
    }

    inline void RenderBufferObject::getParameteriv(GLenum property, GLint* value)
    {
        glGetNamedRenderbufferParameteriv(_handle, property, value);
    }
}

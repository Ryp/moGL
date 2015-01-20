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
    :   _handle(0)
    {
        glCreateRenderbuffers(1, &_handle);
    }

    inline RenderBufferObject::~RenderBufferObject()
    {
        glDeleteRenderbuffers(1, &_handle);
    }

    inline void RenderBufferObject::setStorage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        //Only Target::RenderBuffer is allowed
        glNamedRenderbufferStorage(_handle, internalformat, width, height);
    }

    inline GLuint RenderBufferObject::getHandle() const
    {
        return (_handle);
    }
}

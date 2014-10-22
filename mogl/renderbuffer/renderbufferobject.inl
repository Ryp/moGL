////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "renderbufferobject.hpp"

namespace mogl
{
    RenderBufferObject::RenderBufferObject()
    :   _handle(0)
    {
        glGenRenderbuffers(1, &_handle);
    }

    RenderBufferObject::~RenderBufferObject()
    {
        glDeleteRenderbuffers(1, &_handle);
    }

    void RenderBufferObject::bind()
    {
        //Only Target::RenderBuffer is allowed
        glBindRenderbuffer(static_cast<GLenum>(Target::RenderBuffer), _handle);
    }

    void RenderBufferObject::setStorage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        //Only Target::RenderBuffer is allowed
        glRenderbufferStorage(static_cast<GLenum>(Target::RenderBuffer), internalformat, width, height);
    }

    GLuint RenderBufferObject::getHandle() const
    {
        return (_handle);
    }
}

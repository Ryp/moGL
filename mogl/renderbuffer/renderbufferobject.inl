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
#include "mogl/debug.hpp"

namespace mogl
{
    inline RenderBufferObject::RenderBufferObject()
    :   _handle(0)
    {
        glGenRenderbuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline RenderBufferObject::~RenderBufferObject()
    {
        glDeleteRenderbuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline void RenderBufferObject::bind()
    {
        //Only Target::RenderBuffer is allowed
        glBindRenderbuffer(static_cast<GLenum>(Target::RenderBuffer), _handle); MOGL_GL_CALL();
    }

    inline void RenderBufferObject::setStorage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        //Only Target::RenderBuffer is allowed
        glRenderbufferStorage(static_cast<GLenum>(Target::RenderBuffer), internalformat, width, height); MOGL_GL_CALL();
    }

    inline GLuint RenderBufferObject::getHandle() const
    {
        return (_handle);
    }
}

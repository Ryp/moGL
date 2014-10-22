////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "bufferobject.hpp"

namespace mogl
{
    BufferObject::BufferObject()
    :   _handle(0)
    {
        glGenBuffers(1, &_handle);
    }

    BufferObject::~BufferObject()
    {
        glDeleteBuffers(1, &_handle);
    }

    void BufferObject::bind(GLenum target)
    {
        glBindBuffer(target, _handle);
    }

    GLuint BufferObject::getHandle() const
    {
        return _handle;
    }

    void BufferObject::setData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
    {
        glBufferData(target, size, data, usage);
    }
}

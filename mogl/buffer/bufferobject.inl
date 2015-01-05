////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "bufferobject.hpp"
#include "mogl/debug.hpp"

namespace mogl
{
    inline BufferObject::BufferObject(GLenum target)
    :   _handle(0),
        _target(target)
    {
        glGenBuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline BufferObject::~BufferObject()
    {
        glDeleteBuffers(1, &_handle); MOGL_GL_CALL();
    }

    inline void BufferObject::bind()
    {
        glBindBuffer(_target, _handle); MOGL_GL_CALL();
    }

    inline void BufferObject::setData(GLsizeiptr size, const GLvoid* data, GLenum usage)
    {
        glBufferData(_target, size, data, usage); MOGL_GL_CALL();
    }

    inline GLuint BufferObject::getHandle() const
    {
        return _handle;
    }
}

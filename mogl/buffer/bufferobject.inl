////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline BufferObject::BufferObject(GLenum target)
    :   _target(target)
    {
        glCreateBuffers(1, &_handle);
    }

    inline BufferObject::~BufferObject()
    {
        if (_handle)
            glDeleteBuffers(1, &_handle);
    }

    inline void BufferObject::bind()
    {
        glBindBuffer(_target, _handle);
    }

    inline void BufferObject::setStorage(GLsizeiptr size, const void* data, GLbitfield flags)
    {
        glNamedBufferStorage(_handle, size, data, static_cast<gl::MapBufferUsageMask>(flags)); // TODO Find solution to remove glbinding dependance
    }

    inline void BufferObject::setData(GLsizeiptr size, const void* data, GLenum usage)
    {
        glNamedBufferData(_handle, size, data, usage);
    }

    inline void BufferObject::setSubData(GLintptr offset, GLsizeiptr size, const void* data)
    {
        glNamedBufferSubData(_handle, offset, size, data);
    }

    inline void BufferObject::copySubData(GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
    {
        glCopyNamedBufferSubData(_handle, writeBuffer, readOffset, writeOffset, size);
    }

    inline void BufferObject::clearData(GLenum internalformat, GLenum format, GLenum type, const void* data)
    {
        glClearNamedBufferData(_handle, internalformat, format, type, data);
    }

    inline void BufferObject::clearSubData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data)
    {
        glClearNamedBufferSubData(_handle, internalformat, offset, size, format, type, data);
    }

    inline void* BufferObject::map(GLenum access)
    {
        return glMapNamedBuffer(_handle, access);
    }

    inline void* BufferObject::mapRange(GLintptr offset, GLsizeiptr length, GLbitfield access)
    {
        return glMapNamedBufferRange(_handle, offset, length, static_cast<gl::BufferAccessMask>(access)); // TODO Find solution to remove glbinding dependance
    }

    inline bool BufferObject::unmap()
    {
        return glUnmapNamedBuffer(_handle) == GL_TRUE;
    }

    inline void BufferObject::flushMappedRange(GLintptr offset, GLsizeiptr length)
    {
        glFlushMappedNamedBufferRange(_handle, offset, length);
    }

    template <>
    inline void BufferObject::get<GLint>(GLenum property, GLint* value)
    {
        glGetNamedBufferParameteriv(_handle, property, value);
    }

    template <>
    inline void BufferObject::get<GLint64>(GLenum property, GLint64* value)
    {
        glGetNamedBufferParameteri64v(_handle, property, value);
    }

    template <>
    inline GLint BufferObject::get<GLint>(GLenum property)
    {
        GLint   value;
        glGetNamedBufferParameteriv(_handle, property, &value);
        return value;
    }

    template <>
    inline GLint64 BufferObject::get<GLint64>(GLenum property)
    {
        GLint64 value;
        glGetNamedBufferParameteri64v(_handle, property, &value);
        return value;
    }

    inline void BufferObject::getPointerv(GLenum property, void** value)
    {
        glGetNamedBufferPointerv(_handle, property, value);
    }

    inline void BufferObject::getSubData(GLintptr offset, GLsizeiptr size, void* data)
    {
        glGetNamedBufferSubData(_handle, offset, size, data);
    }

    inline GLenum BufferObject::getTarget() const
    {
        return _target;
    }

    inline bool BufferObject::isValid() const
    {
        return glIsBuffer(_handle) == GL_TRUE;
    }
}

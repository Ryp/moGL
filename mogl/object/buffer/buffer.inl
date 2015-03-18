////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file buffer.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline Buffer::Buffer(GLenum target)
    :   Handle(GL_BUFFER),
        _target(target)
    {
        glCreateBuffers(1, &_handle);
    }

    inline Buffer::~Buffer()
    {
        if (_handle)
            glDeleteBuffers(1, &_handle);
    }

    inline void Buffer::bind()
    {
        glBindBuffer(_target, _handle);
    }

    inline void Buffer::setStorage(GLsizeiptr size, const void* data, GLbitfield flags)
    {
        glNamedBufferStorage(_handle, size, data, static_cast<BufferStorageMask>(flags)); // TODO Find solution to remove glbinding dependance
    }

    inline void Buffer::setData(GLsizeiptr size, const void* data, GLenum usage)
    {
        glNamedBufferData(_handle, size, data, usage);
    }

    inline void Buffer::setSubData(GLintptr offset, GLsizeiptr size, const void* data)
    {
        glNamedBufferSubData(_handle, offset, size, data);
    }

    inline void Buffer::copySubData(GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
    {
        glCopyNamedBufferSubData(_handle, writeBuffer, readOffset, writeOffset, size);
    }

    inline void Buffer::clearData(GLenum internalformat, GLenum format, GLenum type, const void* data)
    {
        glClearNamedBufferData(_handle, internalformat, format, type, data);
    }

    inline void Buffer::clearSubData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data)
    {
        glClearNamedBufferSubData(_handle, internalformat, offset, size, format, type, data);
    }

    inline void Buffer::invalidateData()
    {
        glInvalidateBufferData(_handle);
    }

    inline void Buffer::invalidateSubData(GLintptr offset, GLsizeiptr length)
    {
        glInvalidateBufferSubData(_handle, offset, length);
    }

    inline void* Buffer::map(GLenum access)
    {
        return glMapNamedBuffer(_handle, access);
    }

    inline void* Buffer::mapRange(GLintptr offset, GLsizeiptr length, GLbitfield access)
    {
        return glMapNamedBufferRange(_handle, offset, length, static_cast<BufferAccessMask>(access)); // TODO Find solution to remove glbinding dependance
    }

    inline bool Buffer::unmap()
    {
        return glUnmapNamedBuffer(_handle) == GL_TRUE;
    }

    inline void Buffer::flushMappedRange(GLintptr offset, GLsizeiptr length)
    {
        glFlushMappedNamedBufferRange(_handle, offset, length);
    }

    template <>
    inline void Buffer::get<GLint>(GLenum property, GLint* value)
    {
        glGetNamedBufferParameteriv(_handle, property, value);
    }

    template <>
    inline void Buffer::get<GLint64>(GLenum property, GLint64* value)
    {
        glGetNamedBufferParameteri64v(_handle, property, value);
    }

    template <>
    inline GLint Buffer::get<GLint>(GLenum property)
    {
        GLint   value;
        glGetNamedBufferParameteriv(_handle, property, &value);
        return value;
    }

    template <>
    inline GLint64 Buffer::get<GLint64>(GLenum property)
    {
        GLint64 value;
        glGetNamedBufferParameteri64v(_handle, property, &value);
        return value;
    }

    inline void Buffer::getPointerv(GLenum property, void** value)
    {
        glGetNamedBufferPointerv(_handle, property, value);
    }

    inline void Buffer::getSubData(GLintptr offset, GLsizeiptr size, void* data)
    {
        glGetNamedBufferSubData(_handle, offset, size, data);
    }

    inline GLenum Buffer::getTarget() const
    {
        return _target;
    }

    inline bool Buffer::isValid() const
    {
        return glIsBuffer(_handle) == GL_TRUE;
    }

    inline void Buffer::bindBufferBase(GLuint index)
    {
        glBindBufferBase(_target, index, _handle);
    }

    inline void Buffer::bindBufferRange(GLuint index, GLintptr offset, GLsizeiptr size)
    {
        glBindBufferRange(_target, index, _handle, offset, size);
    }
}

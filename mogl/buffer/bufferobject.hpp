////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Buffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_BUFFEROBJECT_INCLUDED
#define MOGL_BUFFEROBJECT_INCLUDED

namespace mogl
{
    class BufferObject
    {
    public:
        BufferObject(GLenum target);
        ~BufferObject();

        BufferObject(const BufferObject& other) = delete;
        BufferObject& operator=(const BufferObject& other) = delete;

    public:
        void    bind();
        GLuint  getHandle() const;
        void    setStorage(GLsizeiptr size, const void* data, GLbitfield flags);
        void    setData(GLsizeiptr size, const void* data, GLenum usage);
        void    setSubData(GLintptr offset, GLsizeiptr size, const void* data);
        void    copySubData(GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
        void    clearData(GLenum internalformat, GLenum format, GLenum type, const void* data);
        void    clearSubData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
        void*   map(GLenum access);
        void*   mapRange(GLintptr offset, GLsizeiptr length, GLbitfield access);
        bool    unmap();
        void    flushMappedRange(GLintptr offset, GLsizeiptr length);
        void    getParameteriv(GLenum property, int* value);
        void    getParameteri64v(GLenum property, GLint64* value);
        void    getPointerv(GLenum property, void** value);
        void    getSubData(GLintptr offset, GLsizeiptr size, void* data);

    private:
        GLuint  _handle;
        GLenum  _target;
    };
}

#include "bufferobject.inl"

#endif // MOGL_BUFFEROBJECT_INCLUDED

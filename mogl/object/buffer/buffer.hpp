////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file buffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Buffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_BUFFER_INCLUDED
#define MOGL_BUFFER_INCLUDED

#include <mogl/object/handle.hpp>

namespace mogl
{
    class Buffer : public Handle<GLuint>
    {
    protected:
        Buffer(GLenum target);

    public:
        ~Buffer();

        Buffer(const Buffer& other) = delete;
        Buffer& operator=(const Buffer& other) = delete;

        Buffer(Buffer&& other) = default;

    public:
        void    setStorage(GLsizeiptr size, const void* data, GLbitfield flags);
        void    setData(GLsizeiptr size, const void* data, GLenum usage);
        void    setSubData(GLintptr offset, GLsizeiptr size, const void* data);
        void    copySubData(GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
        void    clearData(GLenum internalformat, GLenum format, GLenum type, const void* data);
        void    clearSubData(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
        void    invalidateData();
        void    invalidateSubData(GLintptr offset, GLsizeiptr length);
        void*   map(GLenum access);
        void*   mapRange(GLintptr offset, GLsizeiptr length, GLbitfield access);
        bool    unmap();
        void    flushMappedRange(GLintptr offset, GLsizeiptr length);
        template <class T> void get(GLenum property, T* value); // Direct call to glGetNamedBufferParameter*v()
        template <class T> T    get(GLenum property);
        void*   getBufferPointer(); /* call to glGetNamedBufferPointerv */
        void    getSubData(GLintptr offset, GLsizeiptr size, void* data);
        GLenum  getTarget() const;
        bool    isHandleValid() const override final;

    protected:
        void    bind();
        void    bindBufferBase(GLuint index);
        void    bindBufferRange(GLuint index, GLintptr offset, GLsizeiptr size);

    private:
        const GLenum    _target;
    };
}

#include "buffer.inl"

#endif // MOGL_BUFFER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file bufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_BUFFEROBJECT_INCLUDED
#define MOGL_BUFFEROBJECT_INCLUDED

namespace mogl
{
    class BufferObject
    {
    public:
        BufferObject();
        ~BufferObject();

        BufferObject(const BufferObject& other) = delete;
        BufferObject& operator=(const BufferObject& other) = delete;

    public:
        void    bind(GLenum target);
        GLuint  getHandle() const;

    public:
        static void setData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);

    private:
        GLuint  _handle;
    };
}

#include "bufferobject.inl"

#endif // MOGL_BUFFEROBJECT_INCLUDED

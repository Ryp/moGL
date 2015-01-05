////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
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
        BufferObject(GLenum target);
        ~BufferObject();

        BufferObject(const BufferObject& other) = delete;
        BufferObject& operator=(const BufferObject& other) = delete;

    public:
        void    bind();
        void    setData(GLsizeiptr size, const GLvoid* data, GLenum usage);
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
        GLenum  _target;
    };
}

#include "bufferobject.inl"

#endif // MOGL_BUFFEROBJECT_INCLUDED

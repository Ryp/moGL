////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_RENDERBUFFEROBJECT_INCLUDED
#define MOGL_RENDERBUFFEROBJECT_INCLUDED

namespace mogl
{
    class RenderBufferObject
    {
    public:
        enum class Target {
            RenderBuffer = static_cast<GLenum>(GL_RENDERBUFFER),
        };

    public:
        RenderBufferObject();
        ~RenderBufferObject();

        RenderBufferObject(const RenderBufferObject& other) = delete;
        RenderBufferObject& operator=(const RenderBufferObject& other) = delete;

    public:
        void    bind();
        void    setStorage(GLenum internalformat, GLsizei width, GLsizei height);

    public:
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
    };
}

#include "renderbufferobject.inl"

#endif // MOGL_RENDERBUFFEROBJECT_INCLUDED

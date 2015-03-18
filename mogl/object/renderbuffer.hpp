////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief RenderBuffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_RENDERBUFFER_INCLUDED
#define MOGL_RENDERBUFFER_INCLUDED

#include <mogl/object/handle.hpp>

namespace mogl
{
    class RenderBuffer : public Handle<GLuint>
    {
    public:
        RenderBuffer();
        ~RenderBuffer();

        RenderBuffer(const RenderBuffer& other) = delete;
        RenderBuffer& operator=(const RenderBuffer& other) = delete;

        RenderBuffer(RenderBuffer&& other) = default;

    public:
        void    setStorage(GLenum internalformat, GLsizei width, GLsizei height);
        void    setStorageMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
        void    getParameteriv(GLenum property, GLint* value);
        bool    isValid() const override final;
    };
}

#include "renderbuffer.inl"

#endif // MOGL_RENDERBUFFER_INCLUDED

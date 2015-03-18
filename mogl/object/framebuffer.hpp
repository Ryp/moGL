////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Framebuffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFER_INCLUDED
#define MOGL_FRAMEBUFFER_INCLUDED

#include <mogl/handle.hpp>
#include <mogl/renderbuffer/renderbuffer.hpp>
#include <mogl/texture/texture.hpp>

namespace mogl
{
    class FrameBuffer : public Handle<GLuint>
    {
    public:
        FrameBuffer();
        ~FrameBuffer();

        FrameBuffer(const FrameBuffer& other) = delete;
        FrameBuffer& operator=(const FrameBuffer& other) = delete;

        FrameBuffer(FrameBuffer&& other) = default;

    public:
        void    bind(GLenum target);
        void    setRenderBuffer(GLenum attachment, RenderBuffer& renderbuffer);
        void    setTexture(GLenum attachment, Texture& texture, GLint level = 0);
        void    setDrawBuffer(GLenum buffer);
        void    setDrawBuffers(GLsizei size, const GLenum* buffers);
        void    set(GLenum property, GLint value);
        bool    isComplete(GLenum target);
        bool    isValid() const override final;

    public:
        template <class T>
        void    clear(GLenum buffer, GLint drawbuffer, const T* value);
        void    clear(GLenum buffer, GLfloat depth, GLint stencil);
    };
}

#include "framebuffer.inl"

#endif // MOGL_FRAMEBUFFER_INCLUDED


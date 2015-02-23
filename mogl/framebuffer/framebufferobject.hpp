////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Framebuffer object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFEROBJECT_INCLUDED
#define MOGL_FRAMEBUFFEROBJECT_INCLUDED

#include <mogl/handle.hpp>
#include <mogl/renderbuffer/renderbufferobject.hpp>
#include <mogl/texture/textureobject.hpp>

namespace mogl
{
    class FrameBufferObject : public Handle<>
    {
    public:
        FrameBufferObject();
        ~FrameBufferObject();

        FrameBufferObject(const FrameBufferObject& other) = delete;
        FrameBufferObject& operator=(const FrameBufferObject& other) = delete;

    public:
        void    bind(GLenum target);
        void    setRenderBuffer(GLenum attachment, RenderBufferObject& renderbuffer);
        void    setTexture(GLenum attachment, TextureObject& texture, GLint level = 0);
        void    setParameter(GLenum property, GLint value);
        void    setDrawBuffer(GLenum buffer);
        void    setDrawBuffers(GLsizei size, const GLenum* buffers);
        bool    isComplete(GLenum target);
        bool    isValid() const override final;

    public:
        template <class T>
        void    clear(GLenum buffer, GLint drawbuffer, const T* value);
        void    clear(GLenum buffer, GLfloat depth, GLint stencil);
    };
}

#include "framebufferobject.inl"

#endif // MOGL_FRAMEBUFFEROBJECT_INCLUDED

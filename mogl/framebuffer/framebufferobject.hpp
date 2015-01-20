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

#include <mogl/renderbuffer/renderbufferobject.hpp>
#include <mogl/texture/textureobject.hpp>

namespace mogl
{
    class FrameBufferObject
    {
    public:
        FrameBufferObject();
        ~FrameBufferObject();

        FrameBufferObject(const FrameBufferObject& other) = delete;
        FrameBufferObject& operator=(const FrameBufferObject& other) = delete;

    public:
        void    bind(GLenum target); // TODO change this ?
        void    setRenderBuffer(GLenum attachment, RenderBufferObject& renderbuffer);
        void    setTexture(GLenum attachment, TextureObject& texture, GLint level = 0);
        void    setParameter(GLenum property, GLint value);
        void    setDrawBuffer(GLenum buffer);
        void    setDrawBuffers(GLsizei size, const GLenum* buffers);
        bool    isComplete(GLenum target);

    public:
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
    };
}

#include "framebufferobject.inl"

#endif // MOGL_FRAMEBUFFEROBJECT_INCLUDED

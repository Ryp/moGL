////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFEROBJECT_INCLUDED
#define MOGL_FRAMEBUFFEROBJECT_INCLUDED

#include <mogl/renderbuffer/renderbufferobject.hpp>
#include <mogl/framebuffer/framebufferfunctions.hpp>

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
        void    bind(FrameBuffer::Target target);
        void    setRenderBuffer(FrameBuffer::Attachment attachment, const RenderBufferObject& renderbuffer); // NOTE OpenGL 4.5

    public:
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
    };
}

#include "framebufferobject.inl"

#endif // MOGL_FRAMEBUFFEROBJECT_INCLUDED

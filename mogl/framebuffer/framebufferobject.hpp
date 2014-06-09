////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_FRAMEBUFFEROBJECT_INCLUDED
#define MOGL_FRAMEBUFFEROBJECT_INCLUDED

namespace mogl
{
    class FrameBufferObject
    {
    public:
        enum class Target {
            DrawFrameBuffer = GL_DRAW_FRAMEBUFFER,
            ReadFrameBuffer = GL_READ_FRAMEBUFFER,
            FrameBuffer = GL_FRAMEBUFFER
        };

    public:
        FrameBufferObject();
        ~FrameBufferObject() = default;

        FrameBufferObject(const FrameBufferObject& other) = delete;
        FrameBufferObject& operator=(const FrameBufferObject& other) = delete;

    public:
        void    bind(Target target);
        void    destroy();

    private:
        GLuint  _handle;
    };
}

#include "framebufferobject.inl"

#endif // MOGL_FRAMEBUFFEROBJECT_INCLUDED

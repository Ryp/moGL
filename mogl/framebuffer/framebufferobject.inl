////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebufferobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "framebufferobject.hpp"

namespace mogl
{
    FrameBufferObject::FrameBufferObject()
    :   _handle(0)
    {
        glGenFramebuffers(1, &_handle);
    }

    void FrameBufferObject::bind(Target target)
    {
        glBindFramebuffer(static_cast<GLenum>(target), _handle);
    }

    void FrameBufferObject::destroy()
    {
        glDeleteFramebuffers(1, &_handle);
    }

    GLuint FrameBufferObject::getHandle() const
    {
        return (_handle);
    }

}

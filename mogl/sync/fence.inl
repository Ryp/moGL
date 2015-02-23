////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file fence.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "fence.hpp"

namespace mogl
{
    inline Fence::Fence(GLenum condition, GLbitfield flags)
    {
        _handle = glFenceSync(condition, static_cast<gl::UnusedMask>(flags)); // TODO find solution to remove cast
    }

    inline Fence::~Fence()
    {
        glDeleteSync(_handle);
    }

    inline void Fence::waitSync(GLbitfield flags, GLuint64 timeout)
    {
        glWaitSync(_handle, static_cast<gl::UnusedMask>(flags), timeout);
    }

    inline GLenum Fence::waitClientSync(GLbitfield flags, GLuint64 timeout)
    {
        return glClientWaitSync(_handle, static_cast<gl::SyncObjectMask>(flags), timeout);
    }

    inline bool Fence::isValid() const
    {
        return glIsSync(_handle) == GL_TRUE;
    }
}

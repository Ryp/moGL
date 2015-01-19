////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file states.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "states.hpp"

namespace mogl
{
    inline void enable(GLenum flag)
    {
        glEnable(flag);
    }

    inline void disable(GLenum flag)
    {
        glDisable(flag);
    }

    inline void setActiveTexture(GLenum unit)
    {
        glActiveTexture(unit);
    }

    inline void setViewport(GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glViewport(x, y, width, height);
    }

    inline void setCullFace(GLenum mode)
    {
        glCullFace(mode);
    }
}

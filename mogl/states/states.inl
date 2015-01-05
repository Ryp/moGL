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
#include "mogl/debug.hpp"

namespace mogl
{
    inline void enable(GLenum flag)
    {
        glEnable(flag); MOGL_GL_CALL();
    }

    inline void disable(GLenum flag)
    {
        glDisable(flag); MOGL_GL_CALL();
    }

    inline void setActiveTexture(GLenum unit)
    {
        glActiveTexture(unit); MOGL_GL_CALL();
    }

    inline void setViewport(GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glViewport(x, y, width, height); MOGL_GL_CALL();
    }

    inline void setCullFace(GLenum mode)
    {
        glCullFace(mode); MOGL_GL_CALL();
    }
}

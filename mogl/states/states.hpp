////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file states.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_STATES_INCLUDED
#define MOGL_STATES_INCLUDED

namespace mogl
{
    static void enable(GLenum flag);
    static void disable(GLenum flag);
    static void setActiveTexture(GLenum unit);
    static void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);
    static void setCullFace(GLenum mode);
}

#include "states.inl"

#endif // MOGL_STATES_INCLUDED

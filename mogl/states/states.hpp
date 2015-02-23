////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file states.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_STATES_INCLUDED
#define MOGL_STATES_INCLUDED

namespace mogl
{
    void enable(GLenum flag);
    void disable(GLenum flag);
    void setActiveTexture(GLenum unit);
    void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);
    void setCullFace(GLenum mode);

    template <class T>
    void    get(GLenum parameter, T* value); // Direct call to glGet*v()
    template <class T>
    void    get(GLenum parameter, GLuint index, T* value); // Direct call to glGet*i_v()
    template <class T>
    T       get(GLenum parameter);
    template <class T>
    T       get(GLenum parameter, GLuint index);
}

#include "states.inl"

#endif // MOGL_STATES_INCLUDED

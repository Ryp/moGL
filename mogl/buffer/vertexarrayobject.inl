////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarrayobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "vertexarrayobject.hpp"
#include "mogl/debug.hpp"

namespace mogl
{
    inline VertexArrayObject::VertexArrayObject()
    :   _handle(0)
    {
        glGenVertexArrays(1, &_handle); MOGL_GL_CALL();
    }

    inline VertexArrayObject::~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &_handle); MOGL_GL_CALL();
    }

    inline void VertexArrayObject::bind()
    {
        glBindVertexArray(_handle); MOGL_GL_CALL();
    }

    inline GLuint VertexArrayObject::getHandle() const
    {
        return _handle;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarrayobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "vertexarrayobject.hpp"

namespace mogl
{
    inline VertexArrayObject::VertexArrayObject()
    :   _handle(0)
    {
        glGenVertexArrays(1, &_handle);
    }

    inline VertexArrayObject::~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &_handle);
    }

    inline void VertexArrayObject::bind()
    {
        glBindVertexArray(_handle);
    }

    inline GLuint VertexArrayObject::getHandle() const
    {
        return _handle;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarrayobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_VERTEXARRAYOBJECT_INCLUDED
#define MOGL_VERTEXARRAYOBJECT_INCLUDED

namespace mogl
{
    class VertexArrayObject
    {
    public:
        VertexArrayObject();
        ~VertexArrayObject();

        VertexArrayObject(const VertexArrayObject& other) = delete;
        VertexArrayObject& operator=(const VertexArrayObject& other) = delete;

    public:
        void    bind();
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
    };
}

#include "vertexarrayobject.inl"

#endif // MOGL_VERTEXARRAYOBJECT_INCLUDED

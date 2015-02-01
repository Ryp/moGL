////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarrayobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief VAO object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_VERTEXARRAYOBJECT_INCLUDED
#define MOGL_VERTEXARRAYOBJECT_INCLUDED

/*
 * https://www.opengl.org/registry/specs/ARB/direct_state_access.txt
 * https://www.opengl.org/sdk/docs/man/html/glMapBufferRange.xhtml
 * https://www.opengl.org/registry/specs/ARB/vertex_attrib_binding.txt
 * https://www.opengl.org/wiki/Vertex_Specification
 * https://github.com/g-truc/ogl-samples/blob/master/tests/gl-450-direct-state-access.cpp
 */

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
        void    enableAttrib(GLuint index);
        void    disableAttrib(GLuint index);
        void    setVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset = GLintptr(0), GLsizei stride = 0);
        void    setVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
        void    setElementBuffer(GLuint buffer);
        void    setAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
        void    setAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
        void    setAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
        void    setAttribBinding(GLuint attribindex, GLuint bindingindex);
        void    setBindingDivisor(GLuint bindingindex, GLuint divisor);
        /* TODO see if templates are simpler, or make functions return value */
        void    getParameteriv(GLenum property, GLint* value);
        void    getParameterIndexediv(GLuint index, GLenum property, GLint* value);
        void    getParameterIndexed64iv(GLuint index, GLenum property, GLint64* value);

    private:
        GLuint  _handle;
    };
}

#include "vertexarrayobject.inl"

#endif // MOGL_VERTEXARRAYOBJECT_INCLUDED

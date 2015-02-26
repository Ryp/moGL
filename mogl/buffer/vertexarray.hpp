////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarray.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief VAO object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_VERTEXARRAY_INCLUDED
#define MOGL_VERTEXARRAY_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class VertexArray : public Handle<GLuint>
    {
    public:
        VertexArray();
        ~VertexArray();

        VertexArray(const VertexArray& other) = delete;
        VertexArray& operator=(const VertexArray& other) = delete;

        VertexArray(VertexArray&& other) = default;

    public:
        void    bind();
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
        template <class T> void get(GLenum property, T* value); // Direct call to glGetVertexArray*v()
        template <class T> T    get(GLenum property);
        template <class T> void get(GLuint index, GLenum property, T* value); // Direct call to glGetVertexArrayIndexed*v()
        template <class T> T    get(GLuint index, GLenum property);
        bool    isValid() const override final;
    };
}

#include "vertexarray.inl"

#endif // MOGL_VERTEXARRAY_INCLUDED

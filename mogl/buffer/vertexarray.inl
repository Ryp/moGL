////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarray.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline VertexArray::VertexArray()
    :   Handle(GL_VERTEX_ARRAY)
    {
        glCreateVertexArrays(1, &_handle);
    }

    inline VertexArray::~VertexArray()
    {
        if (_handle)
            glDeleteVertexArrays(1, &_handle);
    }

    inline void VertexArray::bind()
    {
        glBindVertexArray(_handle);
    }

    inline void VertexArray::enableAttrib(GLuint index)
    {
        glEnableVertexArrayAttrib(_handle, index);
    }

    inline void VertexArray::disableAttrib(GLuint index)
    {
        glDisableVertexArrayAttrib(_handle, index);
    }

    inline void VertexArray::setVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
    {
        glVertexArrayVertexBuffer(_handle, bindingindex, buffer, offset, stride);
    }

    inline void VertexArray::setVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides)
    {
        glVertexArrayVertexBuffers(_handle, first, count, buffers, offsets, strides);
    }

    inline void VertexArray::setElementBuffer(GLuint buffer)
    {
        glVertexArrayElementBuffer(_handle, buffer);
    }

    inline void VertexArray::setAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
    {
        glVertexArrayAttribFormat(_handle, attribindex, size, type, normalized, relativeoffset);
    }

    inline void VertexArray::setAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        glVertexArrayAttribIFormat(_handle, attribindex, size, type, relativeoffset);
    }

    inline void VertexArray::setAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        glVertexArrayAttribLFormat(_handle, attribindex, size, type, relativeoffset);
    }

    inline void VertexArray::setAttribBinding(GLuint attribindex, GLuint bindingindex)
    {
        glVertexArrayAttribBinding(_handle, attribindex, bindingindex);
    }

    inline void VertexArray::setBindingDivisor(GLuint bindingindex, GLuint divisor)
    {
        glVertexArrayBindingDivisor(_handle, bindingindex, divisor);
    }

    template <>
    inline void VertexArray::get<GLint>(GLenum property, GLint* value)
    {
        glGetVertexArrayiv(_handle, property, value);
    }

    template <>
    inline GLint VertexArray::get<GLint>(GLenum property)
    {
        GLint   value;
        glGetVertexArrayiv(_handle, property, &value);
        return value;
    }

    template <>
    inline void VertexArray::get<GLint>(GLuint index, GLenum property, GLint* value)
    {
        glGetVertexArrayIndexediv(_handle, index, property, value);
    }

    template <>
    inline void VertexArray::get<GLint64>(GLuint index, GLenum property, GLint64* value)
    {
        glGetVertexArrayIndexed64iv(_handle, index, property, value);
    }

    template <>
    inline GLint VertexArray::get<GLint>(GLuint index, GLenum property)
    {
        GLint   value;
        glGetVertexArrayIndexediv(_handle, index, property, &value);
        return value;
    }

    template <>
    inline GLint64 VertexArray::get<GLint64>(GLuint index, GLenum property)
    {
        GLint64 value;
        glGetVertexArrayIndexed64iv(_handle, index, property, &value);
        return value;
    }

    inline bool VertexArray::isValid() const
    {
        return glIsVertexArray(_handle) == GL_TRUE;
    }
}

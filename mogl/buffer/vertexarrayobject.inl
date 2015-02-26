////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file vertexarrayobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline VertexArrayObject::VertexArrayObject()
    {
        glCreateVertexArrays(1, &_handle);
    }

    inline VertexArrayObject::~VertexArrayObject()
    {
        if (_handle)
            glDeleteVertexArrays(1, &_handle);
    }

    inline void VertexArrayObject::bind()
    {
        glBindVertexArray(_handle);
    }

    inline void VertexArrayObject::enableAttrib(GLuint index)
    {
        glEnableVertexArrayAttrib(_handle, index);
    }

    inline void VertexArrayObject::disableAttrib(GLuint index)
    {
        glDisableVertexArrayAttrib(_handle, index);
    }

    inline void VertexArrayObject::setVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
    {
        glVertexArrayVertexBuffer(_handle, bindingindex, buffer, offset, stride);
    }

    inline void VertexArrayObject::setVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides)
    {
        glVertexArrayVertexBuffers(_handle, first, count, buffers, offsets, strides);
    }

    inline void VertexArrayObject::setElementBuffer(GLuint buffer)
    {
        glVertexArrayElementBuffer(_handle, buffer);
    }

    inline void VertexArrayObject::setAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
    {
        glVertexArrayAttribFormat(_handle, attribindex, size, type, normalized, relativeoffset);
    }

    inline void VertexArrayObject::setAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        glVertexArrayAttribIFormat(_handle, attribindex, size, type, relativeoffset);
    }

    inline void VertexArrayObject::setAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        glVertexArrayAttribLFormat(_handle, attribindex, size, type, relativeoffset);
    }

    inline void VertexArrayObject::setAttribBinding(GLuint attribindex, GLuint bindingindex)
    {
        glVertexArrayAttribBinding(_handle, attribindex, bindingindex);
    }

    inline void VertexArrayObject::setBindingDivisor(GLuint bindingindex, GLuint divisor)
    {
        glVertexArrayBindingDivisor(_handle, bindingindex, divisor);
    }

    inline void VertexArrayObject::getParameteriv(GLenum property, GLint* value)
    {
        glGetVertexArrayiv(_handle, property, value);
    }

    inline void VertexArrayObject::getParameterIndexediv(GLuint index, GLenum property, GLint* value)
    {
        glGetVertexArrayIndexediv(_handle, index, property, value);
    }

    inline void VertexArrayObject::getParameterIndexed64iv(GLuint index, GLenum property, GLint64* value)
    {
        glGetVertexArrayIndexed64iv(_handle, index, property, value);
    }

    inline bool VertexArrayObject::isValid() const
    {
        return glIsVertexArray(_handle) == GL_TRUE;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file textureobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "textureobject.hpp"
#include "mogl/debug.hpp"

namespace mogl
{
    inline TextureObject::TextureObject(GLenum target)
    :   _handle(0),
        _target(target)
    {
        glGenTextures(1, &_handle); MOGL_GL_CALL();
    }

    inline TextureObject::~TextureObject()
    {
        glDeleteTextures(1, &_handle); MOGL_GL_CALL();
    }

    inline void TextureObject::bind()
    {
        glBindTexture(_target, _handle); MOGL_GL_CALL();
    }

    inline void TextureObject::setStorage2D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glTexStorage2D(_target, levels, internalformat, width, height);
    }

    inline void TextureObject::setImage2D(GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)
    {
        glTexImage2D(_target, level, internalFormat, width, height, border, format, type, data); MOGL_GL_CALL();
    }

    inline void TextureObject::generateMipmap()
    {
        glGenerateMipmap(_target); MOGL_GL_CALL();
    }

    inline GLuint TextureObject::getHandle() const
    {
        return _handle;
    }

    inline GLenum TextureObject::getTarget() const
    {
        return _target;
    }

    template <>
    inline void TextureObject::setParameter<GLint>(GLenum property, GLint value)
    {
        glTexParameteri(_target, property, value); MOGL_GL_CALL();
    }

    template <>
    inline void TextureObject::setParameter<GLenum>(GLenum property, GLenum value)
    {
        glTexParameteri(_target, property, static_cast<GLint>(value)); MOGL_GL_CALL();
    }

    template <>
    inline void TextureObject::setParameter<GLfloat>(GLenum property, GLfloat value)
    {
        glTexParameterf(_target, property, value); MOGL_GL_CALL();
    }

    template <>
    inline void TextureObject::setParameterPtr<GLint>(GLenum property, const GLint* value)
    {
        glTexParameteriv(_target, property, value); MOGL_GL_CALL();
    }

    template <>
    inline void TextureObject::setParameterPtr<GLfloat>(GLenum property, const GLfloat* value)
    {
        glTexParameterfv(_target, property, value); MOGL_GL_CALL();
    }
}

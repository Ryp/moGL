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

namespace mogl
{
    TextureObject::TextureObject(GLenum target)
    :   _handle(0),
        _target(target)
    {
        glGenTextures(1, &_handle);
    }

    TextureObject::~TextureObject()
    {
        glDeleteTextures(1, &_handle);
    }

    void TextureObject::bind()
    {
        glBindTexture(_target, _handle);
    }

    void TextureObject::setImage2D(GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)
    {
        glTexImage2D(_target, level, internalFormat, width, height, border, format, type, data);
    }

    void TextureObject::generateMipmap()
    {
        glGenerateMipmap(_target);
    }

    GLuint TextureObject::getHandle() const
    {
        return _handle;
    }

    GLenum TextureObject::getTarget() const
    {
        return _target;
    }

    template <>
    void TextureObject::setParameter<GLint>(GLenum property, GLint value)
    {
        glTexParameteri(_target, property, value);
    }

    template <>
    void TextureObject::setParameter<GLenum>(GLenum property, GLenum value)
    {
        glTexParameteri(_target, property, static_cast<GLint>(value));
    }

    template <>
    void TextureObject::setParameter<GLfloat>(GLenum property, GLfloat value)
    {
        glTexParameterf(_target, property, value);
    }
}

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

    GLuint TextureObject::getHandle() const
    {
        return _handle;
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

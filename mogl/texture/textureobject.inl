////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file textureobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "textureobject.hpp"

namespace mogl
{
    inline TextureObject::TextureObject(GLenum target)
    :   _target(target)
    {
        glCreateTextures(_target, 1, &_handle);
    }

    inline TextureObject::~TextureObject()
    {
        glDeleteTextures(1, &_handle);
    }

    inline void TextureObject::bind(GLuint unit)
    {
        glBindTextureUnit(unit, _handle);
    }

    inline void TextureObject::setStorage2D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glTextureStorage2D(_handle, levels, internalformat, width, height);
    }

    inline void TextureObject::setImage2D(GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)
    {
        glTextureImage2DEXT(_handle, _target, level, internalFormat, width, height, border, format, type, data);
    }

    inline void TextureObject::generateMipmap()
    {
        glGenerateTextureMipmap(_handle);
    }

    inline GLenum TextureObject::getTarget() const
    {
        return _target;
    }

    /*
     * Templated accessors definitions
     */

    template <>
    inline void TextureObject::get<GLint>(GLenum property, GLint* value)
    {
        glGetTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void TextureObject::get<GLfloat>(GLenum property, GLfloat* value)
    {
        glGetTextureParameterfv(_handle, property, value);
    }

    template <>
    inline GLint TextureObject::get<GLint>(GLenum property)
    {
        GLint value;
        glGetTextureParameteriv(_handle, property, &value);
        return value;
    }

    template <>
    inline GLfloat TextureObject::get<GLfloat>(GLenum property)
    {
        GLfloat value;
        glGetTextureParameterfv(_handle, property, &value);
        return value;
    }

    /*
     * Level specific accessors definitions
     */

    template <>
    inline void TextureObject::get<GLint>(GLint level, GLenum property, GLint* value)
    {
        glGetTextureLevelParameteriv(_handle, level, property, value);
    }

    template <>
    inline void TextureObject::get<GLfloat>(GLint level, GLenum property, GLfloat* value)
    {
        glGetTextureLevelParameterfv(_handle, level, property, value);
    }

    template <>
    inline GLint TextureObject::get<GLint>(GLint level, GLenum property)
    {
        GLint value;
        glGetTextureLevelParameteriv(_handle, level, property, &value);
        return value;
    }

    template <>
    inline GLfloat TextureObject::get<GLfloat>(GLint level, GLenum property)
    {
        GLfloat value;
        glGetTextureLevelParameterfv(_handle, level, property, &value);
        return value;
    }

    /*
     * Templated mutators definitions
     */

    template <>
    inline void TextureObject::set<GLint>(GLenum property, GLint value)
    {
        glTextureParameteri(_handle, property, value);
    }

    template <>
    inline void TextureObject::set<GLenum>(GLenum property, GLenum value)
    {
        glTextureParameteri(_handle, property, static_cast<GLint>(value));
    }

    template <>
    inline void TextureObject::set<GLfloat>(GLenum property, GLfloat value)
    {
        glTextureParameterf(_handle, property, value);
    }

    template <>
    inline void TextureObject::set<GLint*>(GLenum property, GLint* value)
    {
        glTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void TextureObject::set<GLfloat*>(GLenum property, GLfloat* value)
    {
        glTextureParameterfv(_handle, property, value);
    }

    template <>
    inline void TextureObject::set<const GLint*>(GLenum property, const GLint* value)
    {
        glTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void TextureObject::set<const GLfloat*>(GLenum property, const GLfloat* value)
    {
        glTextureParameterfv(_handle, property, value);
    }

    inline bool TextureObject::isValid() const
    {
        return glIsTexture(_handle) == GL_TRUE;
    }
}

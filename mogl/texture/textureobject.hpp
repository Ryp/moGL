////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file textureobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Texture object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TEXTUREOBJECT_INCLUDED
#define MOGL_TEXTUREOBJECT_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class TextureObject : public Handle<>
    {
    public:
        TextureObject(GLenum target);
        ~TextureObject();

        TextureObject(const TextureObject& other) = delete;
        TextureObject& operator=(const TextureObject& other) = delete;

    public:
        void    bind(GLuint unit);
        void    setStorage2D(GLsizei levels, GLenum internalformat,
                             GLsizei width, GLsizei height);
        void    setImage2D(GLint level, GLint internalFormat, GLsizei width,
                           GLsizei height, GLint border, GLenum format,
                           GLenum type, const GLvoid* data); // TODO is this GL 4.5 core ?
        void    generateMipmap();
        GLenum  getTarget() const;
        template <class T> void get(GLenum property, T* value); // Direct call to glGetTextureParameter*v()
        template <class T> T    get(GLenum property);
        template <class T> void get(GLint level, GLenum property, T* value); // Direct call to glGetTextureLevelParameter*v()
        template <class T> T    get(GLint level, GLenum property);
        template <class T> void set(GLenum property, T value);
        bool    isValid() const override final;

    private:
        const GLenum    _target;
    };
}

#include "textureobject.inl"

#endif // MOGL_TEXTUREOBJECT_INCLUDED

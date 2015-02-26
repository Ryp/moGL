////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file texture.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Texture object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TEXTURE_INCLUDED
#define MOGL_TEXTURE_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class Texture : public Handle<GLuint>
    {
    public:
        Texture(GLenum target);
        ~Texture();

        Texture(const Texture& other) = delete;
        Texture& operator=(const Texture& other) = delete;

        Texture(Texture&& other) = default;

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

#include "texture.inl"

#endif // MOGL_TEXTURE_INCLUDED

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

#include <mogl/object/handle.hpp>

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
        void    setBuffer(GLenum internalformat, GLuint buffer);
        void    setBufferRange(GLenum internalformat, GLuint buffer,
                               GLintptr offset, GLsizeiptr size);
        void    setStorage1D(GLsizei levels, GLenum internalformat, GLsizei width);
        void    setStorage2D(GLsizei levels, GLenum internalformat,
                             GLsizei width, GLsizei height);
        void    setStorage3D(GLsizei levels, GLenum internalformat,
                             GLsizei width, GLsizei height, GLsizei depth);
        void    setStorage2DMultisample(GLsizei samples, GLenum internalformat,
                                        GLsizei width, GLsizei height,
                                        GLboolean fixedsamplelocations);
        void    setStorage3DMultisample(GLsizei samples, GLenum internalformat,
                                        GLsizei width, GLsizei height, GLsizei depth,
                                        GLboolean fixedsamplelocations);
        void    setSubImage1D(GLint level, GLint xoffset, GLsizei width,
                              GLenum format, GLenum type, const void* pixels);
        void    setSubImage2D(GLint level, GLint xoffset, GLint yoffset,
                              GLsizei width, GLsizei height, GLenum format,
                              GLenum type, const void* pixels);
        void    setSubImage3D(GLint level, GLint xoffset, GLint yoffset,
                              GLint zoffset, GLsizei width, GLsizei height,
                              GLsizei depth, GLenum format, GLenum type,
                              const void* pixels);
        void    setCompressedSubImage1D(GLint level, GLint xoffset,
                                        GLsizei width, GLenum format,
                                        GLsizei imageSize, const void* data);
        void    setCompressedSubImage2D(GLint level, GLint xoffset,
                                        GLint yoffset, GLsizei width,
                                        GLsizei height, GLenum format,
                                        GLsizei imageSize, const void* data);
        void    setCompressedSubImage3D(GLint level, GLint xoffset,
                                        GLint yoffset, GLint zoffset,
                                        GLsizei width, GLsizei height,
                                        GLsizei depth, GLenum format,
                                        GLsizei imageSize, const void* data);
        void    copySubImage1D(GLint level, GLint xoffset, GLint x, GLint y,
                               GLsizei width);
        void    copySubImage2D(GLint level, GLint xoffset, GLint yoffset,
                               GLint x, GLint y, GLsizei width, GLsizei height);
        void    copySubImage3D(GLint level, GLint xoffset, GLint yoffset,
                               GLint zoffset, GLint x, GLint y, GLsizei width,
                               GLsizei height);
        void    generateMipmap();
        void    getImage(GLint level, GLenum format, GLenum type,
                         GLsizei bufSize, void* pixels);
        void    getCompressedImage(GLint level, GLsizei bufSize, void* pixels);
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

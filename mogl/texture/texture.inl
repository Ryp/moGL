////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file texture.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline Texture::Texture(GLenum target)
    :   Handle(GL_TEXTURE),
        _target(target)
    {
        glCreateTextures(_target, 1, &_handle);
    }

    inline Texture::~Texture()
    {
        if (_handle)
            glDeleteTextures(1, &_handle);
    }

    inline void Texture::bind(GLuint unit)
    {
        glBindTextureUnit(unit, _handle);
    }

    inline void Texture::setBuffer(GLenum internalformat, GLuint buffer)
    {
        glTextureBuffer(_handle, internalformat, buffer);
    }

    inline void Texture::setBufferRange(GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
    {
        glTextureBufferRange(_handle, internalformat, buffer, offset, size);
    }

    inline void Texture::setStorage1D(GLsizei levels, GLenum internalformat, GLsizei width)
    {
        glTextureStorage1D(_handle, levels, internalformat, width);
    }

    inline void Texture::setStorage2D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glTextureStorage2D(_handle, levels, internalformat, width, height);
    }

    inline void Texture::setStorage3D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
    {
        glTextureStorage3D(_handle, levels, internalformat, width, height, depth);
    }

    inline void Texture::setStorage2DMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
    {
        glTextureStorage2DMultisample(_handle, samples, internalformat, width, height, fixedsamplelocations);
    }

    inline void Texture::setStorage3DMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
    {
        glTextureStorage3DMultisample(_handle, samples, internalformat, width, height, depth, fixedsamplelocations);
    }

    inline void Texture::setSubImage1D(GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels)
    {
        glTextureSubImage1D(_handle, level, xoffset, width, format, type, pixels);
    }

    inline void Texture::setSubImage2D(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels)
    {
        glTextureSubImage2D(_handle, level, xoffset, yoffset, width, height, format, type, pixels);
    }

    inline void Texture::setSubImage3D(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels)
    {
        glTextureSubImage3D(_handle, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    }

    inline void Texture::setCompressedSubImage1D(GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data)
    {
        glCompressedTextureSubImage1D(_handle, level, xoffset, width, format, imageSize, data);
    }

    inline void Texture::setCompressedSubImage2D(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)
    {
        glCompressedTextureSubImage2D(_handle, level, xoffset, yoffset, width, height, format, imageSize, data);
    }

    inline void Texture::setCompressedSubImage3D(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data)
    {
        glCompressedTextureSubImage3D(_handle, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    }

    inline void Texture::copySubImage1D(GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
    {
        glCopyTextureSubImage1D(_handle, level, xoffset, x, y, width);
    }

    inline void Texture::copySubImage2D(GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glCopyTextureSubImage2D(_handle, level, xoffset, yoffset, x, y, width, height);
    }

    inline void Texture::copySubImage3D(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glCopyTextureSubImage3D(_handle, level, xoffset, yoffset, zoffset, x, y, width, height);
    }

    inline void Texture::setImage2D(GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)
    {
        glTextureImage2DEXT(_handle, _target, level, internalFormat, width, height, border, format, type, data);
    }

    inline void Texture::generateMipmap()
    {
        glGenerateTextureMipmap(_handle);
    }

    inline void Texture::getImage(GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels)
    {
        glGetTextureImage(_handle, level, format, type, bufSize, pixels);
    }

    inline void Texture::getCompressedImage(GLint level, GLsizei bufSize, void* pixels)
    {
        glGetCompressedTextureImage(_handle, level, bufSize, pixels);
    }

    inline GLenum Texture::getTarget() const
    {
        return _target;
    }

    /*
     * Templated accessors definitions
     */

    template <>
    inline void Texture::get<GLint>(GLenum property, GLint* value)
    {
        glGetTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void Texture::get<GLfloat>(GLenum property, GLfloat* value)
    {
        glGetTextureParameterfv(_handle, property, value);
    }

    template <>
    inline GLint Texture::get<GLint>(GLenum property)
    {
        GLint value;
        glGetTextureParameteriv(_handle, property, &value);
        return value;
    }

    template <>
    inline GLfloat Texture::get<GLfloat>(GLenum property)
    {
        GLfloat value;
        glGetTextureParameterfv(_handle, property, &value);
        return value;
    }

    /*
     * Level specific accessors definitions
     */

    template <>
    inline void Texture::get<GLint>(GLint level, GLenum property, GLint* value)
    {
        glGetTextureLevelParameteriv(_handle, level, property, value);
    }

    template <>
    inline void Texture::get<GLfloat>(GLint level, GLenum property, GLfloat* value)
    {
        glGetTextureLevelParameterfv(_handle, level, property, value);
    }

    template <>
    inline GLint Texture::get<GLint>(GLint level, GLenum property)
    {
        GLint value;
        glGetTextureLevelParameteriv(_handle, level, property, &value);
        return value;
    }

    template <>
    inline GLfloat Texture::get<GLfloat>(GLint level, GLenum property)
    {
        GLfloat value;
        glGetTextureLevelParameterfv(_handle, level, property, &value);
        return value;
    }

    /*
     * Templated mutators definitions
     */

    template <>
    inline void Texture::set<GLint>(GLenum property, GLint value)
    {
        glTextureParameteri(_handle, property, value);
    }

    template <>
    inline void Texture::set<GLenum>(GLenum property, GLenum value)
    {
        glTextureParameteri(_handle, property, static_cast<GLint>(value));
    }

    template <>
    inline void Texture::set<GLfloat>(GLenum property, GLfloat value)
    {
        glTextureParameterf(_handle, property, value);
    }

    template <>
    inline void Texture::set<GLint*>(GLenum property, GLint* value)
    {
        glTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void Texture::set<GLfloat*>(GLenum property, GLfloat* value)
    {
        glTextureParameterfv(_handle, property, value);
    }

    template <>
    inline void Texture::set<const GLint*>(GLenum property, const GLint* value)
    {
        glTextureParameteriv(_handle, property, value);
    }

    template <>
    inline void Texture::set<const GLfloat*>(GLenum property, const GLfloat* value)
    {
        glTextureParameterfv(_handle, property, value);
    }

    inline bool Texture::isValid() const
    {
        return glIsTexture(_handle) == GL_TRUE;
    }
}

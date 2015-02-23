////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sampler.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "sampler.hpp"

namespace mogl
{
    inline Sampler::Sampler()
    {
        glCreateSamplers(1, &_handle);
    }

    inline Sampler::~Sampler()
    {
        glDeleteSamplers(1, &_handle);
    }

    template <>
    inline void Sampler::set<GLint>(GLenum property, GLint value)
    {
        glSamplerParameteri(_handle, property, value);
    }

    template <>
    inline void Sampler::set<GLenum>(GLenum property, GLenum value)
    {
        glSamplerParameteri(_handle, property, static_cast<GLint>(value));
    }

    template <>
    inline void Sampler::set<GLfloat>(GLenum property, GLfloat value)
    {
        glSamplerParameterf(_handle, property, value);
    }

    template <>
    inline void Sampler::set<GLint*>(GLenum property, GLint* value)
    {
        glSamplerParameteriv(_handle, property, value);
    }

    template <>
    inline void Sampler::set<GLfloat*>(GLenum property, GLfloat* value)
    {
        glSamplerParameterfv(_handle, property, value);
    }

    template <>
    inline void Sampler::set<const GLint*>(GLenum property, const GLint* value)
    {
        glSamplerParameteriv(_handle, property, value);
    }

    template <>
    inline void Sampler::set<const GLfloat*>(GLenum property, const GLfloat* value)
    {
        glSamplerParameterfv(_handle, property, value);
    }

    inline bool Sampler::isValid() const
    {
        return glIsSampler(_handle) == GL_TRUE;
    }
}

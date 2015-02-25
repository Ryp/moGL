////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sampler.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SAMPLER_INCLUDED
#define MOGL_SAMPLER_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class Sampler : public Handle<>
    {
    public:
        Sampler();
        ~Sampler();

        Sampler(const Sampler& other) = delete;
        Sampler& operator=(const Sampler& other) = delete;

    public:
        void    bind(GLuint unit);
        template <class T> void get(GLenum property, T* value); // Direct call to glGetSamplerParameter*v()
        template <class T> T    get(GLenum property);
        template <class T> void set(GLenum property, T value);
        bool    isValid() const override final;
    };
}

#include "sampler.inl"

#endif // MOGL_SAMPLER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file textureobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TEXTUREOBJECT_INCLUDED
#define MOGL_TEXTUREOBJECT_INCLUDED

namespace mogl
{
    class TextureObject
    {
    public:
        TextureObject();
        ~TextureObject();

        TextureObject(const TextureObject& other) = delete;
        TextureObject& operator=(const TextureObject& other) = delete;

    public:
        void    bind(GLenum target);
        GLuint  getHandle() const;

    private:
        GLuint  _handle;
    };
}

#include "textureobject.inl"

#endif // MOGL_TEXTUREOBJECT_INCLUDED

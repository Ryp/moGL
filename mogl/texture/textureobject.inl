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
    TextureObject::TextureObject()
    :   _handle(0)
    {
        glGenTextures(1, &_handle);
    }

    TextureObject::~TextureObject()
    {
        glDeleteTextures(1, &_handle);
    }

    void TextureObject::bind(GLenum target)
    {
        glBindTexture(target, _handle);
    }

    GLuint TextureObject::getHandle() const
    {
        return _handle;
    }
}

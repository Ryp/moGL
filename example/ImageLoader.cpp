////////////////////////////////////////////////////////////////////////////////
/// ReaperGL
///
/// Copyright (c) 2015 Thibault Schueller
///
/// @file imageloader.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "ImageLoader.hpp"

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

using namespace gl;

#include <mogl/texture/texture.hpp>

#include <gli/gli.hpp>
#include <gli/core/load_dds.hpp>

void ImageLoader::loadDDS(const std::string& file, mogl::Texture& texture)
{
    gli::texture2D gliTexture(gli::load_dds(file.c_str()));
    if (gliTexture.empty())
        throw (std::runtime_error("could not load texture"));
    texture.set(GL_TEXTURE_BASE_LEVEL, 0);
    texture.set(GL_TEXTURE_MAX_LEVEL, GLint(gliTexture.levels() - 1));
    texture.set(GL_TEXTURE_SWIZZLE_R, GL_RED);
    texture.set(GL_TEXTURE_SWIZZLE_G, GL_GREEN);
    texture.set(GL_TEXTURE_SWIZZLE_B, GL_BLUE);
    texture.set(GL_TEXTURE_SWIZZLE_A, GL_ALPHA);
    texture.setStorage2D(
                   GLint(gliTexture.levels()),
                   GLenum(gli::internal_format(gliTexture.format())),
                   GLsizei(gliTexture.dimensions().x),
                   GLsizei(gliTexture.dimensions().y));
    for (gli::texture2D::size_type Level = 0; Level < gliTexture.levels(); ++Level)
    {
        if (gli::is_compressed(gliTexture.format()))
            glCompressedTextureSubImage2D(texture.getHandle(),
                                      GLint(Level),
                                      0, 0,
                                      GLsizei(gliTexture[Level].dimensions().x),
                                      GLsizei(gliTexture[Level].dimensions().y),
                                      GLenum(gli::internal_format(gliTexture.format())),
                                      GLsizei(gliTexture[Level].size()),
                                      gliTexture[Level].data()
            );
        else
            glTextureSubImage2D(texture.getHandle(),
                                GLint(Level),
                                0, 0,
                                GLsizei(gliTexture[Level].dimensions().x),
                                GLsizei(gliTexture[Level].dimensions().y),
                                GLenum(gli::external_format(gliTexture.format())),
                                GLenum(gli::type_format(gliTexture.format())),
                                gliTexture[Level].data()
            );
    }
}

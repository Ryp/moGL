////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file texture.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

using mogl::TextureObject;

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);
    {
        TextureObject   frameTexture(GL_TEXTURE_2D);

        glActiveTexture(GL_TEXTURE0);
        frameTexture.bind();
        frameTexture.setImage2D(0, static_cast<GLint>(GL_RGB), ctx.getWindowSize().x, ctx.getWindowSize().y, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
        frameTexture.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        frameTexture.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        frameTexture.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        frameTexture.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        TextureObject   depthTexture(GL_TEXTURE_2D);

        glActiveTexture(GL_TEXTURE1);
        depthTexture.bind();
        depthTexture.setImage2D(0, static_cast<GLint>(GL_DEPTH_COMPONENT16), 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
        depthTexture.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        depthTexture.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        depthTexture.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        depthTexture.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        depthTexture.setParameter(GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
        depthTexture.setParameter(GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
    }
    ctx.destroy();
    return (0);
}

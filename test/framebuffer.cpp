////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class FrameBufferObjectTest : public GLTestFixture {};

using mogl::FrameBufferObject;

TEST_F(FrameBufferObjectTest, instantiation)
{
    FrameBufferObject           fbo;
    mogl::TextureObject         colorTexture(GL_TEXTURE_2D);
    mogl::RenderBufferObject    depthRenderBuffer;

    colorTexture.setImage2D(0, static_cast<GLint>(GL_RGB16F), _ctx.getWindowSize().x, _ctx.getWindowSize().y, 0, GL_RGB, GL_HALF_FLOAT, 0);
    colorTexture.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    colorTexture.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    colorTexture.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    colorTexture.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    depthRenderBuffer.setStorage(GL_DEPTH_COMPONENT, _ctx.getWindowSize().x, _ctx.getWindowSize().y);

    colorTexture.bind(0);
    fbo.setTexture(GL_COLOR_ATTACHMENT0, colorTexture);
    fbo.setRenderBuffer(GL_DEPTH_ATTACHMENT, depthRenderBuffer);
    fbo.setDrawBuffer(GL_COLOR_ATTACHMENT0);
    if (!fbo.isComplete(GL_FRAMEBUFFER))
        throw (std::runtime_error("bad framebuffer"));
}

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

class FrameBufferTest : public GLTestFixture {};

using mogl::FrameBuffer;

TEST_F(FrameBufferTest, instantiation)
{
    FrameBuffer           fbo;
    mogl::Texture         colorTexture(GL_TEXTURE_2D);
    mogl::RenderBuffer    depthRenderBuffer;
    GLfloat                     clearColor[] = { 0.0f, 0.0f, 0.5 };

    colorTexture.setImage2D(0, static_cast<GLint>(GL_RGB16F), _ctx.getWindowSize().x, _ctx.getWindowSize().y, 0, GL_RGB, GL_HALF_FLOAT, 0);
    colorTexture.set(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    colorTexture.set(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    colorTexture.set(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    colorTexture.set(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    depthRenderBuffer.setStorage(GL_DEPTH_COMPONENT, _ctx.getWindowSize().x, _ctx.getWindowSize().y);

    colorTexture.bind(0);
    fbo.setTexture(GL_COLOR_ATTACHMENT0, colorTexture);
    fbo.setRenderBuffer(GL_DEPTH_ATTACHMENT, depthRenderBuffer);
    fbo.setDrawBuffer(GL_COLOR_ATTACHMENT0);
    if (!fbo.isComplete(GL_FRAMEBUFFER))
        throw (std::runtime_error("bad framebuffer"));
    fbo.clear<GLfloat>(GL_COLOR, 0, clearColor);

    EXPECT_TRUE(fbo.isValid());
}

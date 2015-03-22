////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class FrameBufferTest : public GLTestFixture {};

using mogl::FrameBuffer;
using mogl::Texture;
using mogl::RenderBuffer;

TEST_F(FrameBufferTest, instantiation)
{
    FrameBuffer     fbo;
    Texture         colorTexture(GL_TEXTURE_2D);
    RenderBuffer    depthRenderBuffer;
    GLfloat         clearColor[] = { 0.0f, 0.0f, 0.5f };

    colorTexture.setStorage2D(1, GL_RGB16F, _ctx.getWindowSize().x, _ctx.getWindowSize().y);
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

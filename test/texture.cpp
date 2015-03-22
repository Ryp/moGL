////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file texture.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class TextureTest : public GLTestFixture {};

using mogl::Texture;
using mogl::Sampler;

TEST_F(TextureTest, texture)
{
    Texture frameTexture(GL_TEXTURE_2D);
    Texture depthTexture(GL_TEXTURE_2D);
    Sampler sampler;
    GLfloat border[] = {1.0f, 0.0f, 0.0f, 0.0f };

    frameTexture.setStorage2D(1, GL_RGBA16F, _ctx.getWindowSize().x, _ctx.getWindowSize().y);
    frameTexture.set(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    frameTexture.set(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    frameTexture.set(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    frameTexture.set(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    frameTexture.set(GL_TEXTURE_BORDER_COLOR, border);

    depthTexture.setStorage2D(1, GL_DEPTH_COMPONENT32F, _ctx.getWindowSize().x, _ctx.getWindowSize().y);
    depthTexture.set(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    depthTexture.set(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    depthTexture.set(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    depthTexture.set(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    depthTexture.set(GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    depthTexture.set(GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    depthTexture.set(GL_TEXTURE_BORDER_COLOR, border);

    sampler.set(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    sampler.set(GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
}

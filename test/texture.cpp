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

class TextureTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(40, 30, 4, 5); };
    void TearDown() override final { _ctx.destroy(); };

protected:
    GLContext   _ctx;
};

using mogl::TextureObject;

TEST_F(TextureTest, frame_texture)
{
    TextureObject   frameTexture(GL_TEXTURE_2D);
    GLfloat         border[] = {1.0f, 0.0f, 0.0f, 0.0f};

    frameTexture.setImage2D(0, static_cast<GLint>(GL_RGB), _ctx.getWindowSize().x, _ctx.getWindowSize().y, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    frameTexture.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    frameTexture.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    frameTexture.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    frameTexture.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    frameTexture.setParameterPtr(GL_TEXTURE_BORDER_COLOR, border);
    frameTexture.bind();
}

TEST_F(TextureTest, depth_texture)
{
    TextureObject   depthTexture(GL_TEXTURE_2D);

    depthTexture.setImage2D(0, static_cast<GLint>(GL_DEPTH_COMPONENT16), 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    depthTexture.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    depthTexture.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    depthTexture.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    depthTexture.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    depthTexture.setParameter(GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    depthTexture.setParameter(GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    depthTexture.bind();
}

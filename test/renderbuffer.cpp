////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file renderbuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class RenderBufferTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(40, 30, 4, 5); };
    void TearDown() override final { _ctx.destroy(); };

protected:
    GLContext   _ctx;
};

using mogl::RenderBufferObject;

TEST_F(RenderBufferTest, binding)
{
    RenderBufferObject  rbo;

    rbo.setStorage(GL_DEPTH_COMPONENT, 1024, 1024);
    rbo.getHandle();
}

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

class RenderBufferTest : public GLTestFixture {};

using mogl::RenderBuffer;

TEST_F(RenderBufferTest, binding)
{
    RenderBuffer  rbo;

    rbo.setStorage(GL_DEPTH_COMPONENT, 1024, 1024);
    rbo.getHandle();

    EXPECT_TRUE(rbo.isValid());
}

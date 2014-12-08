////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file framebuffer.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class FrameBufferObjectTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(40, 30, false); };
    void TearDown() override final { _ctx.destroy(); };

protected:
    GLContext   _ctx;
};

using mogl::FrameBufferObject;

TEST_F(FrameBufferObjectTest, instantiation)
{
    FrameBufferObject   fbo;

    fbo.bind(mogl::FrameBuffer::Target::DrawFrameBuffer);
}

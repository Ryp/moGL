////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file debug.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class DebugTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(40, 30, 4, 5); };
    void TearDown() override final { _ctx.destroy(); };

protected:
    GLContext   _ctx;
};

TEST_F(DebugTest, enum_assert)
{
    glActiveTexture(GL_TEXTURE0); EXPECT_NO_THROW(MOGL_ASSERT_GLSTATE());
    glActiveTexture(GL_COLOR); EXPECT_THROW(MOGL_ASSERT_GLSTATE(), mogl::MoGLException);
}

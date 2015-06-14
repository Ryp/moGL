////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file debug.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class DebugTest : public GLTestFixture {};

TEST_F(DebugTest, enum_assert)
{
    glActiveTexture(GL_TEXTURE0); EXPECT_NO_THROW(MOGL_ASSERT_GLSTATE());
    glActiveTexture(GL_COLOR); EXPECT_THROW(MOGL_ASSERT_GLSTATE(), mogl::MoGLException);

    EXPECT_TRUE(mogl::Debug::getGLSLTypeString(GL_UNSIGNED_INT_VEC4) == "uvec4");
    EXPECT_TRUE(mogl::Debug::getGLSLTypeString(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY) == "usampler2DMSArray");
}

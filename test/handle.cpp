////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file handle.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class HandleTest : public GLTestFixture {};

TEST_F(HandleTest, timer)
{
    mogl::UniformBuffer ubo;
    mogl::Texture       tex(GL_TEXTURE_2D);
    mogl::Fence         fence(GL_SYNC_GPU_COMMANDS_COMPLETE);
    std::string         label("toto");

    ubo.setLabel(label);
    EXPECT_EQ(label, ubo.getLabel());

    tex.setLabel(label);
    EXPECT_EQ(label, tex.getLabel());

    fence.setLabel(label);
    EXPECT_EQ(label, fence.getLabel());
}

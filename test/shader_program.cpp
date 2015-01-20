////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader_program.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

#include <fstream>

class ShaderProgramTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(40, 30, 4, 5); };
    void TearDown() override final { _ctx.destroy(); };

protected:
    GLContext   _ctx;
};

using mogl::ShaderObject;
using mogl::ShaderProgram;

TEST_F(ShaderProgramTest, linking)
{
    std::ifstream   vsFile("data/shader001-valid.vert");
    std::ifstream   fsFile("data/shader001-valid.frag");
    ShaderObject    vertex(vsFile, ShaderObject::ShaderType::VertexShader);
    ShaderObject    fragment(fsFile, ShaderObject::ShaderType::FragmentShader);
    ShaderProgram   shader;

    EXPECT_TRUE(vertex.compile()) << vertex.getLog();
    EXPECT_TRUE(fragment.compile()) << fragment.getLog();

    EXPECT_NO_THROW(shader.attach(vertex));
    EXPECT_NO_THROW(shader.attach(fragment));

    ASSERT_TRUE(shader.link()) << shader.getLog();
    ASSERT_NO_THROW(shader.use());

    GLfloat color[4];
    color[0] = 1.0f;

    ASSERT_NO_THROW(shader.setUniformPtr<4>("color", color));
    ASSERT_NO_THROW(shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "customColor"));
    ASSERT_NO_THROW(shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "redColor"));

    EXPECT_NO_THROW(shader.detach(vertex));
    EXPECT_NO_THROW(shader.detach(fragment));
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader_program.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

#include <fstream>

using mogl::ShaderObject;
using mogl::ShaderProgram;

class ShaderProgramTest : public ::testing::Test
{
public:
    void SetUp() override final { _ctx.create(400, 300, false); };
    void TearDown() override final { _ctx.destroy(); };

private:
    GLContext   _ctx;
};

TEST_F(ShaderProgramTest, SimpleLinking)
{
    std::ifstream   vsFile("data/shader001-valid.vert");
    std::ifstream   fsFile("data/shader001-valid.frag");
    ShaderObject    vertex(vsFile, ShaderObject::ShaderType::VertexShader);
    ShaderObject    fragment(fsFile, ShaderObject::ShaderType::FragmentShader);
    ShaderProgram   shader;

    EXPECT_TRUE(vertex.compile()) << vertex.getLog();
    EXPECT_TRUE(fragment.compile()) << fragment.getLog();

    shader.attach(vertex);
    shader.attach(fragment);

    EXPECT_TRUE(shader.link()) << shader.getLog();

    GLfloat color[4];
    color[0] = 1.0f;

    shader.setUniformPtr<4>("color", color);
    shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "customColor");
    shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "redColor");
}

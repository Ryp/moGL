////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader_program.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include <fstream>

class ShaderProgramTest : public GLTestFixture {};

using mogl::Shader;
using mogl::ShaderProgram;

TEST_F(ShaderProgramTest, linking)
{
    std::ifstream   vsFile("data/shader001-valid.vert");
    std::ifstream   fsFile("data/shader001-valid.frag");
    Shader          vertex(vsFile, GL_VERTEX_SHADER);
    Shader          fragment(fsFile, GL_FRAGMENT_SHADER);
    ShaderProgram   shader;

    EXPECT_TRUE(vertex.compile()) << vertex.getLog();
    EXPECT_TRUE(fragment.compile()) << fragment.getLog();

    EXPECT_TRUE(vertex.isValid());
    EXPECT_TRUE(fragment.isValid());
    EXPECT_TRUE(shader.isValid());

    EXPECT_NO_THROW(shader.attach(vertex));
    EXPECT_NO_THROW(shader.attach(fragment));

    ASSERT_TRUE(shader.link()) << shader.getLog();
    ASSERT_NO_THROW(shader.use());
    shader.printDebug();

    GLfloat color[4];
    color[0] = 1.0f;

    ASSERT_NO_THROW(shader.setUniformPtr<4>("color", color));
    ASSERT_NO_THROW(shader.setUniformSubroutine(GL_FRAGMENT_SHADER, "colorSelector", "redColor"));
    ASSERT_NO_THROW(shader.setUniformSubroutine(GL_FRAGMENT_SHADER, "colorSelector", "customColor"));

    EXPECT_NO_THROW(shader.detach(vertex));
    EXPECT_NO_THROW(shader.detach(fragment));
}

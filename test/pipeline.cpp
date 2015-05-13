////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file pipeline.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include <fstream>

class ProgramPipelineTest : public GLTestFixture {};

using mogl::Shader;
using mogl::ShaderProgram;
using mogl::ProgramPipeline;

TEST_F(ProgramPipelineTest, linking)
{
    std::ifstream   vsFile("data/shader001-valid.vert");
    std::ifstream   fsFile("data/shader001-valid.frag");
    Shader          vertex(GL_VERTEX_SHADER);
    Shader          fragment(GL_FRAGMENT_SHADER);
    ShaderProgram   shader;
    ProgramPipeline pipeline;

    EXPECT_TRUE(vertex.compile(vsFile)) << vertex.getLog();
    EXPECT_TRUE(fragment.compile(fsFile)) << fragment.getLog();

    EXPECT_TRUE(vertex.isHandleValid());
    EXPECT_TRUE(fragment.isHandleValid());
    EXPECT_TRUE(shader.isHandleValid());

    EXPECT_NO_THROW(shader.attach(vertex));
    EXPECT_NO_THROW(shader.attach(fragment));

    ASSERT_TRUE(shader.link()) << shader.getLog();
    ASSERT_NO_THROW(shader.use());

    pipeline.setActiveProgram(shader.getHandle());
    // TODO test program pipeline
}

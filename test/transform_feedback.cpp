////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transform_feedback.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include <fstream>

class TransformFeedbackTest : public GLTestFixture {};

using mogl::VBO;
using mogl::VAO;
using mogl::TFBO;
using mogl::Shader;
using mogl::Query;
using mogl::ShaderProgram;
using mogl::TransformFeedback;

TEST_F(TransformFeedbackTest, test)
{
    std::ifstream       vsFile("data/transform_feedback.vert");
    std::ifstream       gsFile("data/transform_feedback.geom");
    Shader              vertex(vsFile, GL_VERTEX_SHADER);
    Shader              geometry(gsFile, GL_GEOMETRY_SHADER);
    ShaderProgram       shader;
    Query               query(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
    VAO                 vao;
    VBO                 vbo;
    TFBO                tfbo;
    const GLchar*       feedbackVaryings[] = { "outValue" };
    GLfloat             data[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
    GLfloat             feedback[15];
    GLuint              primitives;

    ASSERT_TRUE(vertex.compile());
    ASSERT_TRUE(geometry.compile());
    shader.attach(vertex);
    shader.attach(geometry);

    shader.setTransformFeedbackVaryings(1, feedbackVaryings, GL_INTERLEAVED_ATTRIBS);
    ASSERT_TRUE(shader.link());
    shader.use();
    shader.printDebug();

    vao.bind();

    vbo.bind();
    vbo.setData(sizeof(data), data, GL_STATIC_DRAW);

    GLint inputAttrib = shader.getAttribLocation("inValue");

    vao.enableAttrib(inputAttrib);
    glVertexAttribPointer(inputAttrib, 1, GL_FLOAT, GL_FALSE, 0, 0);

    tfbo.setData(sizeof(data) * 3, nullptr, GL_STATIC_READ);
    tfbo.bindBufferBase(0);

    mogl::enable(GL_RASTERIZER_DISCARD);
    query.begin();
    TransformFeedback::begin(GL_TRIANGLES);
    glDrawArrays(GL_POINTS, 0, 5);
    TransformFeedback::end();
    query.end();
    mogl::disable(GL_RASTERIZER_DISCARD);
    mogl::Sync::flush();

    primitives = query.get<GLuint>(GL_QUERY_RESULT);
    tfbo.getSubData(0, sizeof(feedback), feedback);
    std::cout << primitives << " primitives written" << std::endl;
    for (unsigned int i = 0; i < 15; ++i)
        std::cout << feedback[i] << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file buffer_object.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class BufferTest : public GLTestFixture {};

using mogl::Buffer;

Buffer    createVbo()
{
    Buffer    vbo(GL_ARRAY_BUFFER);
    std::size_t     size = 3 * 4;
    float           buffer[size];

    vbo.setData(sizeof(buffer[0]) * size, buffer, GL_STATIC_DRAW);
    EXPECT_TRUE(vbo.isValid());
    return vbo;
}

TEST_F(BufferTest, vbo)
{
    Buffer    vbo(createVbo()); // Use move semantics

    EXPECT_TRUE(vbo.isValid());
}

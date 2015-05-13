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

using mogl::ArrayBuffer;

ArrayBuffer    createVbo()
{
    ArrayBuffer vbo;
    std::size_t size = 3 * 4;
    float       buffer[size];

    vbo.setData(sizeof(buffer[0]) * size, buffer, GL_STATIC_DRAW);
    EXPECT_TRUE(vbo.isHandleValid());
    return vbo;
}

TEST_F(BufferTest, vbo)
{
    ArrayBuffer vbo(createVbo()); // Use move semantics

    EXPECT_TRUE(vbo.isHandleValid());
}

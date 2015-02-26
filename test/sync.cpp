////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sync.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

class FenceTest : public GLTestFixture {};

using mogl::Fence;
using mogl::Buffer;
using mogl::VertexArray;

TEST_F(FenceTest, fence)
{
//     Fence       fence(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
//     VertexArray vao;
//     Buffer      vbo(GL_ARRAY_BUFFER);
//     std::size_t vboSize = 12;
// //     float       vertices[vboSize];
//     GLbitfield  flags = reinterpret_cast<GLbitfield>(GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
//     void*       dataPtr = nullptr;
//     GLenum      waitReturn = GL_UNSIGNALED;
//
//     vbo.setStorage(vboSize, nullptr, flags);
//     dataPtr = vbo.mapRange(0, vboSize, flags);
//
//     waitReturn = fence.waitClientSync(reinterpret_cast<GLbitfield>(GL_SYNC_FLUSH_COMMANDS_BIT), GLuint64(0));
//     if (waitReturn == GL_ALREADY_SIGNALED)
//         return ;
}

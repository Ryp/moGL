////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sync.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class FenceTest : public GLTestFixture {};

using mogl::Fence;
using mogl::BufferObject;
using mogl::VertexArrayObject;

TEST_F(FenceTest, fence)
{
    Fence               fence(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    VertexArrayObject   vao;
    BufferObject        vbo(GL_ARRAY_BUFFER);
    unsigned int        vboSize = 12;
//     float               vertices[vboSize];
    GLbitfield          flags = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT;
    void*               dataPtr = nullptr;
    GLenum              waitReturn = GL_UNSIGNALED;

    vbo.setStorage(vboSize, nullptr, flags);
    dataPtr = vbo.mapRange(0, vboSize, flags);

    waitReturn = fence.waitClientSync(GL_SYNC_FLUSH_COMMANDS_BIT, 0);
    if (waitReturn == GL_ALREADY_SIGNALED)
        return ;
}

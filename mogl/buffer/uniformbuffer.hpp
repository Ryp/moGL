////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file uniformbuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_UNIFORMBUFFER_INCLUDED
#define MOGL_UNIFORMBUFFER_INCLUDED

#include <mogl/buffer/buffer.hpp>

namespace mogl
{
    class UniformBuffer : public Buffer
    {
    public:
        UniformBuffer() : Buffer(GL_UNIFORM_BUFFER) {}
        ~UniformBuffer() = default;

        UniformBuffer(const UniformBuffer& other) = delete;
        UniformBuffer& operator=(const UniformBuffer& other) = delete;

        UniformBuffer(UniformBuffer&& other) = default;

    public:
        using Buffer::bindBufferBase;
        using Buffer::bindBufferRange;
    };

    using UBO = UniformBuffer;
}

#endif // MOGL_UNIFORMBUFFER_INCLUDED

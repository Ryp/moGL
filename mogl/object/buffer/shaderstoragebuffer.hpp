////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderstoragebuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SHADERSTORAGEBUFFER_INCLUDED
#define MOGL_SHADERSTORAGEBUFFER_INCLUDED

#include <mogl/object/buffer/buffer.hpp>

namespace mogl
{
    class ShaderStorageBuffer : public Buffer
    {
    public:
        ShaderStorageBuffer() : Buffer(GL_SHADER_STORAGE_BUFFER) {}
        ~ShaderStorageBuffer() = default;

        ShaderStorageBuffer(const ShaderStorageBuffer& other) = delete;
        ShaderStorageBuffer& operator=(const ShaderStorageBuffer& other) = delete;

        ShaderStorageBuffer(ShaderStorageBuffer&& other) = default;

    public:
        using Buffer::bindBufferBase;
        using Buffer::bindBufferRange;
    };

    using SSBO = ShaderStorageBuffer;
}

#endif // MOGL_SHADERSTORAGEBUFFER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file arraybuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_ARRAYBUFFER_INCLUDED
#define MOGL_ARRAYBUFFER_INCLUDED

#include <mogl/buffer/buffer.hpp>

namespace mogl
{
    class ArrayBuffer : public Buffer
    {
    public:
        ArrayBuffer() : Buffer(GL_ARRAY_BUFFER) {}
        ~ArrayBuffer() = default;

        ArrayBuffer(const ArrayBuffer& other) = delete;
        ArrayBuffer& operator=(const ArrayBuffer& other) = delete;

        ArrayBuffer(ArrayBuffer&& other) = default;

    public:
        using Buffer::bind;
    };

    using VBO = ArrayBuffer;
}

#endif // MOGL_ARRAYBUFFER_INCLUDED

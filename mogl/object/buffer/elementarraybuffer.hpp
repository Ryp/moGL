////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file elementarraybuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_ELEMENTARRAYBUFFER_INCLUDED
#define MOGL_ELEMENTARRAYBUFFER_INCLUDED

#include <mogl/buffer/buffer.hpp>

namespace mogl
{
    class ElementArrayBuffer : public Buffer
    {
    public:
        ElementArrayBuffer() : Buffer(GL_ELEMENT_ARRAY_BUFFER) {}
        ~ElementArrayBuffer() = default;

        ElementArrayBuffer(const ElementArrayBuffer& other) = delete;
        ElementArrayBuffer& operator=(const ElementArrayBuffer& other) = delete;

        ElementArrayBuffer(ElementArrayBuffer&& other) = default;

    public:
        using Buffer::bind;
    };

    using EBO = ElementArrayBuffer;
}

#endif // MOGL_ELEMENTARRAYBUFFER_INCLUDED

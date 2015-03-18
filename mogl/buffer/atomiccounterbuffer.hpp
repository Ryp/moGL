////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file atomiccounterbuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_ATOMICCOUNTERBUFFER_INCLUDED
#define MOGL_ATOMICCOUNTERBUFFER_INCLUDED

#include <mogl/buffer/buffer.hpp>

namespace mogl
{
    class AtomicCounterBuffer : public Buffer
    {
    public:
        AtomicCounterBuffer() : Buffer(GL_ATOMIC_COUNTER_BUFFER) {}
        ~AtomicCounterBuffer() = default;

        AtomicCounterBuffer(const AtomicCounterBuffer& other) = delete;
        AtomicCounterBuffer& operator=(const AtomicCounterBuffer& other) = delete;

        AtomicCounterBuffer(AtomicCounterBuffer&& other) = default;
    };
}

#endif // MOGL_ATOMICCOUNTERBUFFER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transformfeedbackbuffer.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TRANSFORMFEEDBACKBUFFER_INCLUDED
#define MOGL_TRANSFORMFEEDBACKBUFFER_INCLUDED

#include <mogl/buffer/buffer.hpp>

namespace mogl
{
    class TransformFeedbackBuffer : public Buffer
    {
    public:
        TransformFeedbackBuffer() : Buffer(GL_TRANSFORM_FEEDBACK_BUFFER) {}
        ~TransformFeedbackBuffer() = default;

        TransformFeedbackBuffer(const TransformFeedbackBuffer& other) = delete;
        TransformFeedbackBuffer& operator=(const TransformFeedbackBuffer& other) = delete;

        TransformFeedbackBuffer(TransformFeedbackBuffer&& other) = default;

    public:
        using Buffer::bindBufferBase;
        using Buffer::bindBufferRange;
    };

    using TFBO = TransformFeedbackBuffer;
}

#endif // MOGL_TRANSFORMFEEDBACKBUFFER_INCLUDED

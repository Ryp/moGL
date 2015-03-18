////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transformfeedback.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TRANSFORMFEEDBACK_INCLUDED
#define MOGL_TRANSFORMFEEDBACK_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class TransformFeedback : public Handle<GLuint>
    {
    public:
        TransformFeedback();
        ~TransformFeedback();

        TransformFeedback(const TransformFeedback& other) = delete;
        TransformFeedback& operator=(const TransformFeedback& other) = delete;

        TransformFeedback(TransformFeedback&& other) = default;

    public:
        void    bind(GLenum target = GL_TRANSFORM_FEEDBACK);
        bool    isValid() const override final;

    public:
        static void begin(GLenum primitiveMode);
        static void end();
        static void pause();
        static void resume();
    };
}

#include "transformfeedback.inl"

#endif // MOGL_TRANSFORMFEEDBACK_INCLUDED

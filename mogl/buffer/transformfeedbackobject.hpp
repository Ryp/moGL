////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transformfeedbackobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_TRANSFORMFEEDBACKOBJECT_INCLUDED
#define MOGL_TRANSFORMFEEDBACKOBJECT_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class TransformFeedbackObject : public Handle<GLuint>
    {
    public:
        TransformFeedbackObject();
        ~TransformFeedbackObject();

        TransformFeedbackObject(const TransformFeedbackObject& other) = delete;
        TransformFeedbackObject& operator=(const TransformFeedbackObject& other) = delete;

        TransformFeedbackObject(TransformFeedbackObject&& other) = default;

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

#include "transformfeedbackobject.inl"

#endif // MOGL_TRANSFORMFEEDBACKOBJECT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transformfeedbackobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "transformfeedbackobject.hpp"

namespace mogl
{
    inline TransformFeedbackObject::TransformFeedbackObject()
    {
        glCreateTransformFeedbacks(1, &_handle);
    }

    inline TransformFeedbackObject::~TransformFeedbackObject()
    {
        glDeleteTransformFeedbacks(1, &_handle);
    }

    inline void TransformFeedbackObject::bind(GLenum target)
    {
        glBindTransformFeedback(target, _handle);
    }

    inline bool TransformFeedbackObject::isValid() const
    {
        return glIsTransformFeedback(_handle) == GL_TRUE;
    }

    inline void TransformFeedbackObject::begin(GLenum primitiveMode)
    {
        glBeginTransformFeedback(primitiveMode);
    }

    inline void TransformFeedbackObject::end()
    {
        glEndTransformFeedback();
    }

    inline void TransformFeedbackObject::pause()
    {
        glPauseTransformFeedback();
    }

    inline void TransformFeedbackObject::resume()
    {
        glResumeTransformFeedback();
    }
}

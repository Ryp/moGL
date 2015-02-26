////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file transformfeedback.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline TransformFeedback::TransformFeedback()
    {
        glCreateTransformFeedbacks(1, &_handle);
    }

    inline TransformFeedback::~TransformFeedback()
    {
        if (_handle)
            glDeleteTransformFeedbacks(1, &_handle);
    }

    inline void TransformFeedback::bind(GLenum target)
    {
        glBindTransformFeedback(target, _handle);
    }

    inline bool TransformFeedback::isValid() const
    {
        return glIsTransformFeedback(_handle) == GL_TRUE;
    }

    inline void TransformFeedback::begin(GLenum primitiveMode)
    {
        glBeginTransformFeedback(primitiveMode);
    }

    inline void TransformFeedback::end()
    {
        glEndTransformFeedback();
    }

    inline void TransformFeedback::pause()
    {
        glPauseTransformFeedback();
    }

    inline void TransformFeedback::resume()
    {
        glResumeTransformFeedback();
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file states.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "states.hpp"

namespace mogl
{
    inline void enable(GLenum flag)
    {
        glEnable(flag);
    }

    inline void disable(GLenum flag)
    {
        glDisable(flag);
    }

    inline void setActiveTexture(GLenum unit)
    {
        glActiveTexture(unit);
    }

    inline void setViewport(GLint x, GLint y, GLsizei width, GLsizei height)
    {
        glViewport(x, y, width, height);
    }

    inline void setCullFace(GLenum mode)
    {
        glCullFace(mode);
    }

    /*
     * get<> specialization for typed arrays
     */

    template <>
    inline void get<GLboolean>(GLenum parameter, GLboolean* value)
    {
        glGetBooleanv(parameter, value);
    }

    template <>
    inline void get<GLfloat>(GLenum parameter, GLfloat* value)
    {
        glGetFloatv(parameter, value);
    }

    template <>
    inline void get<GLdouble>(GLenum parameter, GLdouble* value)
    {
        glGetDoublev(parameter, value);
    }

    template <>
    inline void get<GLint>(GLenum parameter, GLint* value)
    {
        glGetIntegerv(parameter, value);
    }

    template <>
    inline void get<GLint64>(GLenum parameter, GLint64* value)
    {
        glGetInteger64v(parameter, value);
    }

    /*
     * get<> specialization for indexed typed arrays
     */

    template <>
    inline void get<GLboolean>(GLenum parameter, GLuint index, GLboolean* value)
    {
        glGetBooleani_v(parameter, index, value);
    }

    template <>
    inline void get<GLfloat>(GLenum parameter, GLuint index, GLfloat* value)
    {
        glGetFloati_v(parameter, index, value);
    }

    template <>
    inline void get<GLdouble>(GLenum parameter, GLuint index, GLdouble* value)
    {
        glGetDoublei_v(parameter, index, value);
    }

    template <>
    inline void get<GLint>(GLenum parameter, GLuint index, GLint* value)
    {
        glGetIntegeri_v(parameter, index, value);
    }

    template <>
    inline void get<GLint64>(GLenum parameter, GLuint index, GLint64* value)
    {
        glGetInteger64i_v(parameter, index, value);
    }

    /*
     * get<> specialization for single return value
     */

    template <>
    inline GLboolean get<GLboolean>(GLenum parameter)
    {
        GLboolean   value;
        glGetBooleanv(parameter, &value);
        return value;
    }

    template <>
    inline GLfloat get<GLfloat>(GLenum parameter)
    {
        GLfloat     value;
        glGetFloatv(parameter, &value);
        return value;
    }

    template <>
    inline GLdouble get<GLdouble>(GLenum parameter)
    {
        GLdouble    value;
        glGetDoublev(parameter, &value);
        return value;
    }

    template <>
    inline GLint get<GLint>(GLenum parameter)
    {
        GLint       value;
        glGetIntegerv(parameter, &value);
        return value;
    }

    template <>
    inline GLint64 get<GLint64>(GLenum parameter)
    {
        GLint64     value;
        glGetInteger64v(parameter, &value);
        return value;
    }

    /*
     * get<> specialization for single indexed return value
     */

    template <>
    inline GLboolean get<GLboolean>(GLenum parameter, GLuint index)
    {
        GLboolean   value;
        glGetBooleani_v(parameter, index, &value);
        return value;
    }

    template <>
    inline GLfloat get<GLfloat>(GLenum parameter, GLuint index)
    {
        GLfloat     value;
        glGetFloati_v(parameter, index, &value);
        return value;
    }

    template <>
    inline GLdouble get<GLdouble>(GLenum parameter, GLuint index)
    {
        GLdouble    value;
        glGetDoublei_v(parameter, index, &value);
        return value;
    }

    template <>
    inline GLint get<GLint>(GLenum parameter, GLuint index)
    {
        GLint       value;
        glGetIntegeri_v(parameter, index, &value);
        return value;
    }

    template <>
    inline GLint64 get<GLint64>(GLenum parameter, GLuint index)
    {
        GLint64     value;
        glGetInteger64i_v(parameter, index, &value);
        return value;
    }
}

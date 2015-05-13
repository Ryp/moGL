////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file states.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

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
    
    inline bool isEnabled(GLenum flag)
    {
        return glIsEnabled(flag) == GL_TRUE;
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

    template <>
    inline void setPixelStore<GLint>(GLenum property, GLint value)
    {
        glPixelStorei(property, value);
    }
    
    template <>
    inline void setPixelStore<GLfloat>(GLenum property, GLfloat value)
    {
        glPixelStoref(property, value);
    }

    /*
     * get<> specialization for typed arrays
     */

    template <>
    inline void get<GLboolean>(GLenum property, GLboolean* value)
    {
        glGetBooleanv(property, value);
    }

    template <>
    inline void get<GLfloat>(GLenum property, GLfloat* value)
    {
        glGetFloatv(property, value);
    }

    template <>
    inline void get<GLdouble>(GLenum property, GLdouble* value)
    {
        glGetDoublev(property, value);
    }

    template <>
    inline void get<GLint>(GLenum property, GLint* value)
    {
        glGetIntegerv(property, value);
    }

    template <>
    inline void get<GLint64>(GLenum property, GLint64* value)
    {
        glGetInteger64v(property, value);
    }

    /*
     * get<> specialization for single return value
     */

    template <>
    inline GLboolean get<GLboolean>(GLenum property)
    {
        GLboolean   value;
        glGetBooleanv(property, &value);
        return value;
    }

    template <>
    inline GLfloat get<GLfloat>(GLenum property)
    {
        GLfloat     value;
        glGetFloatv(property, &value);
        return value;
    }

    template <>
    inline GLdouble get<GLdouble>(GLenum property)
    {
        GLdouble    value;
        glGetDoublev(property, &value);
        return value;
    }

    template <>
    inline GLint get<GLint>(GLenum property)
    {
        GLint       value;
        glGetIntegerv(property, &value);
        return value;
    }

    template <>
    inline GLint64 get<GLint64>(GLenum property)
    {
        GLint64     value;
        glGetInteger64v(property, &value);
        return value;
    }

    /*
     * get<> specialization for indexed typed arrays
     */

    template <>
    inline void get<GLboolean>(GLenum property, GLuint index, GLboolean* value)
    {
        glGetBooleani_v(property, index, value);
    }

    template <>
    inline void get<GLfloat>(GLenum property, GLuint index, GLfloat* value)
    {
        glGetFloati_v(property, index, value);
    }

    template <>
    inline void get<GLdouble>(GLenum property, GLuint index, GLdouble* value)
    {
        glGetDoublei_v(property, index, value);
    }

    template <>
    inline void get<GLint>(GLenum property, GLuint index, GLint* value)
    {
        glGetIntegeri_v(property, index, value);
    }

    template <>
    inline void get<GLint64>(GLenum property, GLuint index, GLint64* value)
    {
        glGetInteger64i_v(property, index, value);
    }
    
    /*
     * get<> specialization for single indexed return value
     */

    template <>
    inline GLboolean get<GLboolean>(GLenum property, GLuint index)
    {
        GLboolean   value;
        glGetBooleani_v(property, index, &value);
        return value;
    }

    template <>
    inline GLfloat get<GLfloat>(GLenum property, GLuint index)
    {
        GLfloat     value;
        glGetFloati_v(property, index, &value);
        return value;
    }

    template <>
    inline GLdouble get<GLdouble>(GLenum property, GLuint index)
    {
        GLdouble    value;
        glGetDoublei_v(property, index, &value);
        return value;
    }

    template <>
    inline GLint get<GLint>(GLenum property, GLuint index)
    {
        GLint       value;
        glGetIntegeri_v(property, index, &value);
        return value;
    }

    template <>
    inline GLint64 get<GLint64>(GLenum property, GLuint index)
    {
        GLint64     value;
        glGetInteger64i_v(property, index, &value);
        return value;
    }
}

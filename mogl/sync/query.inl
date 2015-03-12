////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file query.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline Query::Query(GLenum type)
    :   Handle(GL_QUERY),
        _type(type)
    {
        glCreateQueries(_type, 1, &_handle);
    }

    inline Query::~Query()
    {
        if (_handle)
            glDeleteQueries(1, &_handle);
    }

    inline void Query::begin()
    {
        glBeginQuery(_type, _handle);
    }

    inline void Query::end()
    {
        glEndQuery(_type);
    }

    /*
     * Templated accessors definitions (direct call)
     */

    template <>
    inline void Query::get<GLint>(GLenum property, GLint* rslt)
    {
        glGetQueryObjectiv(_handle, property, rslt);
    }

    template <>
    inline void Query::get<GLuint>(GLenum property, GLuint* rslt)
    {
        glGetQueryObjectuiv(_handle, property, rslt);
    }

    template <>
    inline void Query::get<GLint64>(GLenum property, GLint64* rslt)
    {
        glGetQueryObjecti64v(_handle, property, rslt);
    }

    template <>
    inline void Query::get<GLuint64>(GLenum property, GLuint64* rslt)
    {
        glGetQueryObjectui64v(_handle, property, rslt);
    }

    /*
     * Templated accessors definitions cont'
     */

    template <>
    inline GLint Query::get<GLint>(GLenum property)
    {
        GLint   rslt;
        glGetQueryObjectiv(_handle, property, &rslt);
        return rslt;
    }

    template <>
    inline GLuint Query::get<GLuint>(GLenum property)
    {
        GLuint  rslt;
        glGetQueryObjectuiv(_handle, property, &rslt);
        return rslt;
    }

    template <>
    inline GLint64 Query::get<GLint64>(GLenum property)
    {
        GLint64 rslt;
        glGetQueryObjecti64v(_handle, property, &rslt);
        return rslt;
    }

    template <>
    inline GLuint64 Query::get<GLuint64>(GLenum property)
    {
        GLuint64    rslt;
        glGetQueryObjectui64v(_handle, property, &rslt);
        return rslt;
    }

    inline GLenum Query::getType() const
    {
        return _type;
    }

    inline bool Query::isValid() const
    {
        return glIsQuery(_handle) == GL_TRUE;
    }
}

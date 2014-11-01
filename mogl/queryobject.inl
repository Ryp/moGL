////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file queryobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "queryobject.hpp"

namespace mogl
{
    QueryObject::QueryObject(GLenum type)
    :   _id(0),
        _type(type)
    {
        glGenQueries(1, &_id);
    }

    QueryObject::~QueryObject()
    {
        glDeleteQueries(1, &_id);
    }

    void QueryObject::begin()
    {
        glBeginQuery(_type, _id);
    }

    void QueryObject::end()
    {
        glEndQuery(_type);
    }

    template <>
    GLint QueryObject::getResult(GLenum param)
    {
        GLint   rslt;
        glGetQueryObjectiv(_id, param, &rslt);
        return (rslt);
    }

    template <>
    GLuint QueryObject::getResult(GLenum param)
    {
        GLuint  rslt;
        glGetQueryObjectuiv(_id, param, &rslt);
        return (rslt);
    }

    template <>
    GLint64 QueryObject::getResult(GLenum param)
    {
        GLint64 rslt;
        glGetQueryObjecti64v(_id, param, &rslt);
        return (rslt);
    }

    template <>
    GLuint64 QueryObject::getResult(GLenum param)
    {
        GLuint64    rslt;
        glGetQueryObjectui64v(_id, param, &rslt);
        return (rslt);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file queryobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_QUERYOBJECT_INCLUDED
#define MOGL_QUERYOBJECT_INCLUDED

namespace mogl
{
    class QueryObject
    {
    public:
        QueryObject(GLenum type);
        ~QueryObject();

        QueryObject(const QueryObject& other) = delete;
        QueryObject& operator=(const QueryObject& other) = delete;

    public:
        void    begin();
        void    end();
        template <class T>
        T       getResult(GLenum param);

    private:
        GLuint  _id;
        GLenum  _type;
    };
}

#include "queryobject.inl"

#endif // MOGL_QUERYOBJECT_INCLUDED

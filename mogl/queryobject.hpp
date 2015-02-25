////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file queryobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Query object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_QUERYOBJECT_INCLUDED
#define MOGL_QUERYOBJECT_INCLUDED

#include <mogl/handle.hpp>

namespace mogl
{
    class QueryObject : public Handle<GLuint>
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
        bool    isValid() const override final;

    private:
        GLenum  _type;
    };
}

#include "queryobject.inl"

#endif // MOGL_QUERYOBJECT_INCLUDED

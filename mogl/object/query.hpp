////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file query.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief Query object OO wrapper using OpenGL 4.5 DSA features
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_QUERY_INCLUDED
#define MOGL_QUERY_INCLUDED

#include <mogl/object/handle.hpp>

namespace mogl
{
    class Query : public Handle<GLuint>
    {
    public:
        Query(GLenum type);
        ~Query();

        Query(const Query& other) = delete;
        Query& operator=(const Query& other) = delete;

        Query(Query&& other) = default;

    public:
        void    begin();
        void    end();
        template <class T> void get(GLenum property, T* value); // Direct call to glGetQuery*v()
        template <class T> T    get(GLenum property);
        GLenum  getType() const;
        bool    isValid() const override final;

    private:
        const GLenum    _type;
    };
}

#include "query.inl"

#endif // MOGL_QUERY_INCLUDED

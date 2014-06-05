////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file moglexception.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_MOGLEXCEPTION_INCLUDED
#define MOGL_MOGLEXCEPTION_INCLUDED

#include <stdexcept>

namespace mogl
{
    class MoGLException : public std::runtime_error
    {
    public:
        explicit MoGLException(const std::string& message) : std::runtime_error("MoGL::" + message) {}
        virtual ~MoGLException() {}
    };
}

#endif // MOGL_MOGLEXCEPTION_INCLUDED

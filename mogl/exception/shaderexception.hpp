////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderexception.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SHADEREXCEPTION_INCLUDED
#define MOGL_SHADEREXCEPTION_INCLUDED

#include "exception/moglexception.hpp"

namespace mogl
{
    class ShaderException : public MoGLException
    {
    public:
        explicit ShaderException(const std::string& message) : MoGLException("Shader::" + message) {}
        virtual ~ShaderException() {}
    };
}

#endif // MOGL_SHADEREXCEPTION_INCLUDED

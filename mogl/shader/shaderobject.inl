////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderobject.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "shaderobject.hpp"
#include "mogl/debug.hpp"

#include <vector>
#include <istream>

namespace mogl
{
    inline ShaderObject::ShaderObject(std::istream& sourceFile, ShaderType type)
    :   _code(std::istreambuf_iterator<char>(static_cast<std::istream&>(sourceFile)), std::istreambuf_iterator<char>()),
        _handle(0),
        _type(type),
        _isCompiled(false)
    {}

    inline ShaderObject::ShaderObject(std::string& sourceCode, ShaderType type)
    :   _code(sourceCode),
        _handle(0),
        _type(type),
        _isCompiled(false)
    {}

    inline ShaderObject::~ShaderObject()
    {
        glDeleteShader(_handle); MOGL_GL_CALL();
    }

    inline bool ShaderObject::compile()
    {
        GLint       success;
        GLint       logLength = 0;
        GLuint      handle;
        char const* srcPtr = _code.c_str();

        handle = glCreateShader(static_cast<GLenum>(_type)); MOGL_GL_CALL();
        if (!handle)
            return (false);
        glShaderSource(handle, 1, &srcPtr, 0); MOGL_GL_CALL();
        glCompileShader(handle); MOGL_GL_CALL();
        glGetShaderiv(handle, GL_COMPILE_STATUS, &success); MOGL_GL_CALL();
        if (success == static_cast<GLint>(GL_FALSE))
        {
            glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength); MOGL_GL_CALL();
            if (logLength > 1)
            {
                std::vector<GLchar> infoLog(logLength);
                glGetShaderInfoLog(handle, logLength, &logLength, &infoLog[0]); MOGL_GL_CALL();
                infoLog[logLength - 1] = '\0'; // Overwrite endline
                _log = &infoLog[0];
            }
            glDeleteShader(handle); MOGL_GL_CALL();
            return (false);
        }
        _isCompiled = true;
        _handle = handle;
        _log = std::string();
        return (_isCompiled);
    }

    inline GLuint ShaderObject::getHandle() const
    {
        return (_handle);
    }

    inline const std::string& ShaderObject::getCode() const
    {
        return (_code);
    }

    inline ShaderObject::ShaderType ShaderObject::getType() const
    {
        return (_type);
    }

    inline const std::string& ShaderObject::getLog() const
    {
        return (_log);
    }

    inline bool ShaderObject::isCompiled() const
    {
        return (_isCompiled);
    }
}

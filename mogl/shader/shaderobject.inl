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

#include <vector>
#include <istream>

namespace mogl
{
    ShaderObject::ShaderObject(std::istream& sourceFile, ShaderType type)
    :   _code(std::istreambuf_iterator<char>(static_cast<std::istream&>(sourceFile)), std::istreambuf_iterator<char>()),
    _handle(0),
    _type(type),
    _isCompiled(false)
    {}

    ShaderObject::ShaderObject(std::string& sourceCode, ShaderType type)
    :   _code(sourceCode),
    _handle(0),
    _type(type),
    _isCompiled(false)
    {}

    ShaderObject::~ShaderObject()
    {
        glDeleteShader(_handle);
    }

    bool ShaderObject::compile()
    {
        GLint       success;
        GLint       logLength = 0;
        GLuint      handle;
        char const* srcPtr = _code.c_str();

        if (!(handle = glCreateShader(static_cast<GLenum>(_type))))
            return (false);
        glShaderSource(handle, 1, &srcPtr, 0);
        glCompileShader(handle);
        glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
        if (success == static_cast<GLint>(GL_FALSE))
        {
            glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength);
            if (logLength > 1)
            {
                std::vector<GLchar> infoLog(logLength);
                glGetShaderInfoLog(handle, logLength, &logLength, &infoLog[0]);
                infoLog[logLength - 2] = '\0'; // Overwrite endline
                _log = &infoLog[0];
            }
            glDeleteShader(handle);
            return (false);
        }
        _isCompiled = true;
        _handle = handle;
        _log = std::string();
        return (_isCompiled);
    }

    GLuint ShaderObject::getHandle() const
    {
        return (_handle);
    }

    const std::string& ShaderObject::getCode() const
    {
        return (_code);
    }

    ShaderObject::ShaderType ShaderObject::getType() const
    {
        return (_type);
    }

    const std::string& ShaderObject::getLog() const
    {
        return (_log);
    }

    bool ShaderObject::isCompiled() const
    {
        return (_isCompiled);
    }
}

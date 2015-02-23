////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
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
    inline ShaderObject::ShaderObject(std::istream& sourceFile, ShaderType type)
    :   _code(std::istreambuf_iterator<char>(static_cast<std::istream&>(sourceFile)), std::istreambuf_iterator<char>()),
        _type(type),
        _isCompiled(false)
    {
        _handle = glCreateShader(static_cast<GLenum>(_type));
    }

    inline ShaderObject::ShaderObject(std::string& sourceCode, ShaderType type)
    :   _code(sourceCode),
        _type(type),
        _isCompiled(false)
    {
        _handle = glCreateShader(static_cast<GLenum>(_type));
    }

    inline ShaderObject::~ShaderObject()
    {
        glDeleteShader(_handle);
    }

    inline bool ShaderObject::compile()
    {
        GLint       logLength = 0;
        char const* srcPtr = _code.c_str();

        glShaderSource(_handle, 1, &srcPtr, 0);
        glCompileShader(_handle);
        _isCompiled = (get(GL_COMPILE_STATUS) == static_cast<GLint>(GL_TRUE));
        _log = std::string();
        if (!_isCompiled)
        {
            logLength = get(GL_INFO_LOG_LENGTH);
            if (logLength > 1)
            {
                std::vector<GLchar> infoLog(logLength);
                glGetShaderInfoLog(_handle, logLength, &logLength, &infoLog[0]);
                infoLog[logLength - 1] = '\0'; // Overwrite endline
                _log = &infoLog[0];
            }
        }
        return _isCompiled;
    }

    inline const std::string& ShaderObject::getCode() const
    {
        return _code;
    }

    inline ShaderObject::ShaderType ShaderObject::getType() const
    {
        return _type;
    }

    inline const std::string& ShaderObject::getLog() const
    {
        return _log;
    }

    inline void ShaderObject::get(GLenum parameter, GLint* value)
    {
        glGetShaderiv(_handle, parameter, value);
    }

    inline GLint ShaderObject::get(GLenum parameter)
    {
        GLint   value;
        glGetShaderiv(_handle, parameter, &value);
        return value;
    }

    inline bool ShaderObject::isCompiled() const
    {
        return _isCompiled;
    }

    inline bool ShaderObject::isValid() const
    {
        return glIsShader(_handle) == GL_TRUE;
    }
}

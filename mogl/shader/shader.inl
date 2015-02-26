////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <istream>

namespace mogl
{
    inline Shader::Shader(std::istream& sourceFile, Type type)
    :   _code(std::istreambuf_iterator<char>(static_cast<std::istream&>(sourceFile)), std::istreambuf_iterator<char>()),
        _type(type),
        _isCompiled(false)
    {
        _handle = glCreateShader(static_cast<GLenum>(_type));
    }

    inline Shader::Shader(std::string& sourceCode, Type type)
    :   _code(sourceCode),
        _type(type),
        _isCompiled(false)
    {
        _handle = glCreateShader(static_cast<GLenum>(_type));
    }

    inline Shader::~Shader()
    {
        if (_handle)
            glDeleteShader(_handle);
    }

    inline bool Shader::compile()
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

    inline const std::string& Shader::getCode() const
    {
        return _code;
    }

    inline Shader::Type Shader::getType() const
    {
        return _type;
    }

    inline const std::string& Shader::getLog() const
    {
        return _log;
    }

    inline void Shader::get(GLenum property, GLint* value)
    {
        glGetShaderiv(_handle, property, value);
    }

    inline GLint Shader::get(GLenum property)
    {
        GLint   value;
        glGetShaderiv(_handle, property, &value);
        return value;
    }

    inline bool Shader::isCompiled() const
    {
        return _isCompiled;
    }

    inline bool Shader::isValid() const
    {
        return glIsShader(_handle) == GL_TRUE;
    }
}

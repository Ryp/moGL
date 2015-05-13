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
    inline Shader::Shader(GLenum type)
    :   Handle(GL_SHADER),
        _type(type)
    {
        _handle = glCreateShader(_type);
    }

    inline Shader::~Shader()
    {
        if (_handle)
            glDeleteShader(_handle);
    }

    inline bool Shader::compile(const std::string& source)
    {
        char const* srcPtr = source.c_str();

        glShaderSource(_handle, 1, &srcPtr, 0);
        glCompileShader(_handle);
        return isCompiled();
    }

    inline bool Shader::compile(std::istream& sourceFile)
    {
        std::string source(std::istreambuf_iterator<char>(static_cast<std::istream&>(sourceFile)), std::istreambuf_iterator<char>());
        return compile(source);
    }

    inline const std::string Shader::getSource() const
    {
        GLint               length = get(GL_SHADER_SOURCE_LENGTH);
        std::vector<char>   source(length);

        glGetShaderSource(_handle, length, nullptr, source.data());
        return std::string(source.data(), length);
    }

    inline GLenum Shader::getType() const
    {
        return _type;
    }

    inline const std::string Shader::getLog() const
    {
        GLint   logLength = get(GL_INFO_LOG_LENGTH);

        if (!logLength)
            return std::string();
        std::vector<GLchar> infoLog(logLength);
        glGetShaderInfoLog(_handle, logLength, &logLength, &infoLog[0]);
        return std::string(&infoLog[0]);
    }

    inline void Shader::get(GLenum property, GLint* value) const
    {
        glGetShaderiv(_handle, property, value);
    }

    inline GLint Shader::get(GLenum property) const
    {
        GLint   value;
        glGetShaderiv(_handle, property, &value);
        return value;
    }

    inline bool Shader::isCompiled() const
    {
        return get(GL_COMPILE_STATUS) == static_cast<GLint>(GL_TRUE);
    }

    inline bool Shader::isHandleValid() const
    {
        return glIsShader(_handle) == GL_TRUE;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SHADER_INCLUDED
#define MOGL_SHADER_INCLUDED

#include <string>

#include <mogl/handle.hpp>

namespace mogl
{
    class Shader : public Handle<GLuint>
    {
    public:
        Shader(std::istream& sourceFile, GLenum type);
        Shader(std::string& sourceCode, GLenum type);
        ~Shader();

        Shader(const Shader& other) = delete;
        Shader& operator=(const Shader& other) = delete;

    public:
        bool                compile();
        const std::string&  getCode() const;
        GLenum              getType() const;
        const std::string&  getLog() const;
        void                get(GLenum property, GLint* value); // Direct call to glGetShaderiv()
        GLint               get(GLenum property);
        bool                isCompiled() const;
        bool                isValid() const override final;

    private:
        std::string     _code;
        const GLenum    _type;
        std::string     _log;
        bool            _isCompiled;
    };
}

#include "shader.inl"

#endif // MOGL_SHADER_INCLUDED

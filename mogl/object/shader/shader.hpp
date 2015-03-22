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

#include <mogl/object/handle.hpp>

namespace mogl
{
    class Shader : public Handle<GLuint>
    {
    public:
        Shader(GLenum type);
        ~Shader();

        Shader(const Shader& other) = delete;
        Shader& operator=(const Shader& other) = delete;

    public:
        bool                compile(const std::string& source);
        bool                compile(std::istream& sourceFile);
        const std::string   getSource() const;
        GLenum              getType() const;
        const std::string   getLog() const;
        void                get(GLenum property, GLint* value) const; // Direct call to glGetShaderiv()
        GLint               get(GLenum property) const;
        bool                isCompiled() const;
        bool                isValid() const override final;

    private:
        const GLenum    _type;
    };
}

#include "shader.inl"

#endif // MOGL_SHADER_INCLUDED

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
        enum class Type {
            VertexShader                = GL_VERTEX_SHADER,
            TesselationControlShader    = GL_TESS_CONTROL_SHADER,
            TesselationEvaluationShader = GL_TESS_EVALUATION_SHADER,
            GeometryShader              = GL_GEOMETRY_SHADER,
            FragmentShader              = GL_FRAGMENT_SHADER,
            ComputeShader               = GL_COMPUTE_SHADER
        };

    public:
        Shader(std::istream& sourceFile, Type type);
        Shader(std::string& sourceCode, Type type);
        ~Shader();

        Shader(const Shader& other) = delete;
        Shader& operator=(const Shader& other) = delete;

    public:
        bool                compile();
        const std::string&  getCode() const;
        Type                getType() const;
        const std::string&  getLog() const;
        void                get(GLenum property, GLint* value); // Direct call to glGetShaderiv()
        GLint               get(GLenum property);
        bool                isCompiled() const;
        bool                isValid() const override final;

    private:
        std::string _code;
        Type        _type;
        std::string _log;
        bool        _isCompiled;
    };
}

#include "shader.inl"

#endif // MOGL_SHADER_INCLUDED

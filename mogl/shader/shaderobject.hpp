////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderobject.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SHADEROBJECT_INCLUDED
#define MOGL_SHADEROBJECT_INCLUDED

#include <string>

namespace mogl
{
    class ShaderObject
    {
    public:
        enum class ShaderType {
            VertexShader                = GL_VERTEX_SHADER,
            TesselationControlShader    = GL_TESS_CONTROL_SHADER,
            TesselationEvaluationShader = GL_TESS_EVALUATION_SHADER,
            GeometryShader              = GL_GEOMETRY_SHADER,
            FragmentShader              = GL_FRAGMENT_SHADER,
            ComputeShader               = GL_COMPUTE_SHADER
        };

    public:
        ShaderObject(std::istream& sourceFile, ShaderType type);
        ShaderObject(std::string& sourceCode, ShaderType type);
        ~ShaderObject();

        ShaderObject(const ShaderObject& other) = delete;
        ShaderObject& operator=(const ShaderObject& other) = delete;

    public:
        bool                compile();
        GLuint              getHandle() const;
        const std::string&  getCode() const;
        ShaderType          getType() const;
        const std::string&  getLog() const;
        bool                isCompiled() const;

    private:
        std::string     _code;
        GLuint          _handle;
        ShaderType      _type;
        std::string     _log;
        bool            _isCompiled;
    };

}

#include "shaderobject.inl"

#endif // MOGL_SHADEROBJECT_INCLUDED

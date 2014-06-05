////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderprogram.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SHADERPROGRAM_INCLUDED
#define MOGL_SHADERPROGRAM_INCLUDED

#include <map>

#include "shaderobject.hpp"

namespace mogl
{
    class ShaderProgram
    {
    public:
        ShaderProgram();
        ~ShaderProgram() = default;

        ShaderProgram(const ShaderProgram& other) = delete;
        ShaderProgram& operator=(const ShaderProgram& other) = delete;
    public:
        void                attach(const ShaderObject& object);
        void                detach(const ShaderObject& object);
        bool                link();
        void                bind();
        void                destroy();
        GLuint              getHandle() const;
        const std::string&  getLog() const;
        GLuint              getAttribLocation(const std::string& name) const;
        GLuint              getUniformLocation(const std::string& name) const;

    public:
        void    printDebug();

    private:
        void    retrieveLocations();

    private:
        std::string                     _log;
        std::map<std::string, GLuint>   _attribs;
        std::map<std::string, GLuint>   _uniforms;
        GLuint                          _handle;
    };
}

#include "shaderprogram.inl"

#endif // MOGL_SHADERPROGRAM_INCLUDED

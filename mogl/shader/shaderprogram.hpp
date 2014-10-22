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
        void    setVertexAttribPointer(const std::string& name,
                                       GLint size,
                                       GLenum type,
                                       GLboolean normalized = GL_FALSE,
                                       GLsizei stride = 0,
                                       const void* pointerOffset = nullptr);

    public:
        template <class T>
        void    setUniform(const std::string& name, T v1);
        template <class T>
        void    setUniform(const std::string& name, T v1, T v2);
        template <class T>
        void    setUniform(const std::string& name, T v1, T v2, T v3);
        template <class T>
        void    setUniform(const std::string& name, T v1, T v2, T v3, T v4);
        template <std::size_t Size, class T>
        void    setUniformPtr(const std::string& name, const T* ptr, GLsizei count = 1);

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

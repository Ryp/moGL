////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderprogram.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "shaderprogram.hpp"

#include <iostream>

namespace mogl
{
    ShaderProgram::ShaderProgram()
    :   _handle(0)
    {
        if (!(_handle = glCreateProgram()))
            std::cerr << "Could not create shader program" << std::endl;
    }

    void ShaderProgram::attach(const ShaderObject& object)
    {
        glAttachShader(_handle, object.getHandle());
    }

    void ShaderProgram::detach(const ShaderObject& object)
    {
        glDetachShader(_handle, object.getHandle());
    }

    bool ShaderProgram::link()
    {
        GLint       success;
        GLint       logLength = 0;

        glLinkProgram(_handle);
        glGetProgramiv(_handle, GL_LINK_STATUS, &success);
        if (success == static_cast<GLint>(GL_FALSE))
        {
            glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &logLength);
            if (logLength > 1)
            {
                std::vector<GLchar> infoLog(logLength);
                glGetProgramInfoLog(_handle, logLength, &logLength, &infoLog[0]);
                infoLog[logLength - 1] = '\0'; // Overwrite endline
                _log = &infoLog[0];
            }
            destroy();
            return (false);
        }
        retrieveLocations();
        _log = std::string();
        return (true);
    }

    void ShaderProgram::bind()
    {
        if (!_handle)
            //     throw (ShaderProgramException("Invalid shader program"));
            return ;
        glUseProgram(_handle);
    }

    void ShaderProgram::destroy()
    {
        glDeleteProgram(_handle);
    }

    GLuint ShaderProgram::getHandle() const
    {
        return (_handle);
    }

    const std::string& ShaderProgram::getLog() const
    {
        return (_log);
    }

    GLuint ShaderProgram::getAttribLocation(const std::string& name) const
    {
        std::map<std::string, GLuint>::const_iterator it;

        if ((it = _attribs.find(name)) != _attribs.end())
            return (it->second);
        std::cerr << "Shader attribute \'" << name << "\' does not exist" << std::endl;
        return (-1);
    }

    GLuint ShaderProgram::getUniformLocation(const std::string& name) const
    {
        std::map<std::string, GLuint>::const_iterator it;

        if ((it = _uniforms.find(name)) != _uniforms.end())
            return (it->second);
        std::cerr << "Shader uniform \'" << name << "\' does not exist" << std::endl;
        return (-1);
    }

    void ShaderProgram::printDebug()
    {
        std::cout << "Attributes:" << std::endl;
        for (auto attrib : _attribs)
            std::cout << "Name: " << attrib.first << std::endl;
        std::cout << "Uniforms:" << std::endl;
        for (auto uniform : _uniforms)
            std::cout << "Name: " << uniform.first << std::endl;
    }

    void ShaderProgram::retrieveLocations()
    {
        GLint     n, maxLen;
        GLint     size, location;
        GLsizei   written;
        GLenum    type;
        GLchar*   name;

        glGetProgramiv(_handle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLen);
        glGetProgramiv(_handle, GL_ACTIVE_ATTRIBUTES, &n);
        name = new GLchar[maxLen];
        for (int i = 0; i < n; ++i)
        {
            glGetActiveAttrib(_handle, i, maxLen, &written, &size, &type, name);
            location = glGetAttribLocation(_handle, name);
            _attribs[name] = location;
        }
        delete[] name;
        glGetProgramiv(_handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
        glGetProgramiv(_handle, GL_ACTIVE_UNIFORMS, &n);
        name = new GLchar[maxLen];
        for (int i = 0; i < n; ++i)
        {
            glGetActiveUniform(_handle, i, maxLen, &written, &size, &type, name);
            location = glGetUniformLocation(_handle, name);
            _uniforms[name] = location;
        }
        delete[] name;
    }

    void ShaderProgram::setVertexAttribPointer(const std::string& name, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointerOffset)
    {
        glVertexAttribPointer(getAttribLocation(name), size, type, normalized, stride, pointerOffset);
    }

    /*
     * GLfloat uniform specialization
     */

    template <>
    void    ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1)
    {
        glUniform1f(getUniformLocation(name), v1);
    }

    template <>
    void    ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2)
    {
        glUniform2f(getUniformLocation(name), v1, v2);
    }

    template <>
    void    ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2, GLfloat v3)
    {
        glUniform3f(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    void    ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4)
    {
        glUniform4f(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLint uniform specialization
     */

    template <>
    void    ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1)
    {
        glUniform1i(getUniformLocation(name), v1);
    }

    template <>
    void    ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2)
    {
        glUniform2i(getUniformLocation(name), v1, v2);
    }

    template <>
    void    ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2, GLint v3)
    {
        glUniform3i(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    void    ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2, GLint v3, GLint v4)
    {
        glUniform4i(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLuint uniform specialization
     */

    template <>
    void    ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1)
    {
        glUniform1ui(getUniformLocation(name), v1);
    }

    template <>
    void    ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2)
    {
        glUniform2ui(getUniformLocation(name), v1, v2);
    }

    template <>
    void    ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2, GLuint v3)
    {
        glUniform3ui(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    void    ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2, GLuint v3, GLuint v4)
    {
        glUniform4ui(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLfloat uniform array specialization
     */

    template <>
    void    ShaderProgram::setUniformPtr<1, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform1fv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<2, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform2fv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<3, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform3fv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<4, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform4fv(getUniformLocation(name), count, ptr);
    }

    /*
     * GLint uniform array specialization
     */

    template <>
    void    ShaderProgram::setUniformPtr<1, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform1iv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<2, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform2iv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<3, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform3iv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<4, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform4iv(getUniformLocation(name), count, ptr);
    }

    /*
     * GLuint uniform array specialization
     */

    template <>
    void    ShaderProgram::setUniformPtr<1, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform1uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<2, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform2uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<3, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform3uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    void    ShaderProgram::setUniformPtr<4, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform4uiv(getUniformLocation(name), count, ptr);
    }
}

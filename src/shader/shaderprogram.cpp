/*
 * Modern OpenGL Wrapper
 *
 * Copyright (c) 2014 Thibault Schueller <ryp.sqrt@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "shaderprogram.hpp"

#include <vector>
#include <iostream>

#include <mogl.hpp>

#include "shaderobject.hpp"

using namespace mogl;

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
    GLint     success = GL_FALSE;
    GLint     logLength = 0;

    glLinkProgram(_handle);
    glGetProgramiv(_handle, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
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
    for (std::map<std::string, GLuint>::iterator it = _attribs.begin(); it != _attribs.end(); ++it)
        std::cout << "Name: " << (*it).first << std::endl;
    std::cout << "Uniforms:" << std::endl;
    for (std::map<std::string, GLuint>::iterator it = _uniforms.begin(); it != _uniforms.end(); ++it)
        std::cout << "Name: " << (*it).first << std::endl;
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

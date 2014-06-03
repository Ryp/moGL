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

#include "shaderobject.hpp"

#include <vector>
#include <istream>

#include <mogl.hpp>

using namespace mogl;

ShaderObject::ShaderObject(std::istream& code, ShaderType type)
:   _code(std::istreambuf_iterator<char>(code), std::istreambuf_iterator<char>()),
    _handle(0),
    _type(type),
    _isCompiled(false)
{}

bool ShaderObject::compile()
{
    GLint       success = GL_FALSE;
    GLint       logLength = 0;
    GLuint      handle;
    char const* srcPtr = _code.c_str();

    if (!(handle = glCreateShader(static_cast<GLenum>(_type))))
        return (false);
    glShaderSource(handle, 1, &srcPtr, 0);
    glCompileShader(handle);
    glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 1)
        {
            std::vector<GLchar> infoLog(logLength);
            glGetShaderInfoLog(handle, logLength, &logLength, &infoLog[0]);
            infoLog[logLength - 2] = '\0'; // Overwrite endline
            _log = &infoLog[0];
        }
        glDeleteShader(handle);
        return (false);
    }
    _isCompiled = true;
    _handle = handle;
    _log = std::string();
    return (_isCompiled);
}

void ShaderObject::destroy()
{
    glDeleteShader(_handle);
}

GLuint ShaderObject::getHandle() const
{
    return (_handle);
}

ShaderObject::ShaderType ShaderObject::getType() const
{
    return (_type);
}

const std::string& ShaderObject::getErrorLog() const
{
    return (_log);
}

bool ShaderObject::isCompiled() const
{
    return (_isCompiled);
}

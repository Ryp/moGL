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

#ifndef MOGL_SHADERPROGRAM_INCLUDED
#define MOGL_SHADERPROGRAM_INCLUDED

#include <string>
#include <map>

#include "shaderobject.hpp"

namespace mogl
{
    class ShaderProgram
    {
    public:
        explicit ShaderProgram();
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
        void    printDebug(); // FIXME Debug only

    private:
        void    retrieveLocations();

    private:
        std::string                     _log;
        std::map<std::string, GLuint>   _attribs;
        std::map<std::string, GLuint>   _uniforms;
        GLuint                          _handle;
    };
}

#endif // MOGL_SHADERPROGRAM_INCLUDED

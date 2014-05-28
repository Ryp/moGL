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

#ifndef MOGL_SHADEROBJECT_INCLUDED
#define MOGL_SHADEROBJECT_INCLUDED

#include <string>

#include "mogl.hpp"

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
        ShaderObject(std::istream& code, ShaderType type);
        ~ShaderObject() = default;

        ShaderObject(const ShaderObject& other) = delete;
        ShaderObject& operator=(const ShaderObject& other) = delete;

    public:
        bool                compile();
        void                destroy();
        GLuint              getHandle() const;
        ShaderType          getType() const;
        const std::string&  getErrorLog() const;
        bool                isCompiled() const;

    private:
        std::string     _code;
        GLuint          _handle;
        ShaderType      _type;
        std::string     _log;
        bool            _isCompiled;
    };
}

#endif // MOGL_SHADEROBJECT_INCLUDED

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

#include "glcontext.hpp" // First to be included
#include <GL/gl.h>

#include "shader/shaderprogram.hpp"

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(40, 30, false);

    std::string         vsFile("#version 330\nin vec3 Position; void main(void) { gl_Position = vec4(Position, 1.0); }");
    std::string         fsFile("#version 330\nout vec4 fragColor; void main(void) { fragColor = vec4(1.0, 0.0, 0.0, 1.0); }");
    mogl::ShaderObject  vertex(vsFile, mogl::ShaderObject::ShaderType::VertexShader);
    mogl::ShaderObject  fragment(fsFile, mogl::ShaderObject::ShaderType::VertexShader);
    mogl::ShaderProgram shader;

    if (!vertex.compile())
        return (1);
    if (!fragment.compile())
        return (2);

    shader.attach(vertex);
    shader.attach(fragment);

    if (shader.link())
        return (3);

    ctx.destroy();
    return (0);
}

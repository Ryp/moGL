////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader_program.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "glcontext.hpp" // First to be included
#include <GL/gl.h>

#include <mogl/shader/shaderprogram.hpp>

using mogl::ShaderObject;
using mogl::ShaderProgram;

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(400, 300, false);

    std::string     vsFile("#version 330\nin vec3 Position; void main(void) { gl_Position = vec4(Position, 1.0); }");
    std::string     fsFile("#version 330\nout vec4 fragColor; void main(void) { fragColor = vec4(1.0, 0.0, 0.0, 1.0); }");
    ShaderObject    vertex(vsFile, ShaderObject::ShaderType::VertexShader);
    ShaderObject    fragment(fsFile, ShaderObject::ShaderType::FragmentShader);
    ShaderProgram   shader;

    if (!vertex.compile())
        return (1);
    if (!fragment.compile())
        return (2);

    shader.attach(vertex);
    shader.attach(fragment);

    if (!shader.link())
        return (3);

    vertex.destroy();
    fragment.destroy();
    shader.destroy();

    ctx.destroy();
    return (0);
}

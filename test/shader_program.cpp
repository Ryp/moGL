////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shader_program.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

using mogl::ShaderObject;
using mogl::ShaderProgram;

static const char vs[] = {
    "#version 420\n"
    ""
    "in vec3 Position;"
    ""
    "void main(void) {"
    "   gl_Position = vec4(Position, 1.0);"
    "}"
};

static const char fs[] = {
    "#version 420\n"
    "out vec4 fragColor;"
    "uniform vec4 color;"
    "subroutine vec4 colorFunc();"
    "subroutine uniform colorFunc colorSelector;"
    ""
    "subroutine (colorFunc)"
    "vec4 customColor() { return color; }"
    ""
    "subroutine (colorFunc)"
    "vec4 redColor() { return vec4(1.0, 0.0, 0.0, 0.0); }"
    ""
    "void main(void) {"
    "   fragColor = colorSelector();"
    "}"
};

int main(int /*ac*/, char** /*av*/)
{
    GLContext ctx;

    ctx.create(400, 300, false);
    {
        std::string     vsFile(vs);
        std::string     fsFile(fs);
        ShaderObject    vertex(vsFile, ShaderObject::ShaderType::VertexShader);
        ShaderObject    fragment(fsFile, ShaderObject::ShaderType::FragmentShader);
        ShaderProgram   shader;

        if (!vertex.compile())
        {
            std::cout << vertex.getLog() << std::endl;
            return 1;
        }
        if (!fragment.compile())
        {
            std::cout << fragment.getLog() << std::endl;
            return 2;
        }

        shader.attach(vertex);
        shader.attach(fragment);

        if (!shader.link())
        {
            std::cout << shader.getLog() << std::endl;
            return 3;
        }

        shader.printDebug();

        GLfloat color[4];
        color[0] = 1.0f;

        shader.setUniformPtr<4>("color", color);
        shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "customColor");
        shader.setUniformSubroutine(ShaderObject::ShaderType::FragmentShader, "colorSelector", "redColor");
    }
    ctx.destroy();
    return 0;
}

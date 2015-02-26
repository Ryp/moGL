#version 450 core

in vec3 Position;

void main(void)
{
    gl_Position = vec4(Position, 1.0);
}

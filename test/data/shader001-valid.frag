#version 450 core

out vec4 fragColor;

uniform vec4 color;

subroutine vec4 colorFunc();
subroutine uniform colorFunc colorSelector;

subroutine (colorFunc)
vec4 customColor() { return color; }

subroutine (colorFunc)
vec4 redColor() { return vec4(1.0, 0.0, 0.0, 0.0); }

void main(void)
{
    fragColor = colorSelector();
}

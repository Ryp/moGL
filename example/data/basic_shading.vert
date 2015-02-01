#version 450 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal_modelspace;
layout(location = 2) in vec2 vertexUV;

out vec2 UV;
out vec3 vertexNormal_cameraspace;
out vec3 lightDirection_cameraspace;

uniform mat4 V;
uniform mat4 MV;
uniform mat4 MVP;

uniform vec3 lightInvDirection_worldspace;

void main()
{
    lightDirection_cameraspace = (V * vec4(lightInvDirection_worldspace, 0)).xyz;
    vertexNormal_cameraspace = (MV * vec4(vertexNormal_modelspace,0)).xyz;
    UV = vertexUV;

    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
}

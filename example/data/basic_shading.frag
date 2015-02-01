#version 450 core

in vec2 UV;
in vec3 vertexNormal_cameraspace;
in vec3 lightDirection_cameraspace;

out vec3 color;

uniform sampler2D uvTex;

void main()
{
    vec3    MaterialDiffuseColor = texture(uvTex, UV).xyz;
    vec3    n = normalize(vertexNormal_cameraspace);
    vec3    l = normalize(lightDirection_cameraspace);
    float   cosTheta = clamp(dot(n, l), 0, 1);

    color = MaterialDiffuseColor * cosTheta;
}

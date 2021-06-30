#version 330 core

uniform vec3 colorChanger;

in vec3 vertexColor;

out vec4 FragColor;

void main()
{
   FragColor = vec4(colorChanger.x*vertexColor.x, colorChanger.y*vertexColor.y, colorChanger.z*vertexColor.z, 1.0);
}

#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;
out vec3 aPosition;
uniform float xOffSet;

void main()
{
	gl_Position = vec4(position.x + xOffSet, position.y, position.z, 1.0);
	ourColor = aColor;
	aPosition = position;
};
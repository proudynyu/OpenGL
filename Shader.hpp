#pragma once

#include <string>
#include <GL/glew.h>
#include <iostream>

static class Shader
{
public:
	static unsigned int CompileShader(const std::string& source, unsigned int type);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};

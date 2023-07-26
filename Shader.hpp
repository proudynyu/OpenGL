#pragma once

#include <string>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

static class Shader
{
public:
	static unsigned int CompileShader(const std::string& source, unsigned int type);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static ShaderProgramSource ParseShader(const std::string& file);
};

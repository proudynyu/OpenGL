#pragma once

#include <string>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
	unsigned int ID;

public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	unsigned int CompileShader(const std::string& source, unsigned int type);
	void CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

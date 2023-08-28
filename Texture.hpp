#pragma once

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "stb_image.h"

class Texture {
public:
	Texture(const char* filename, GLenum format, bool flip_image = false, GLint param = GL_REPEAT);
	~Texture();
	void Load(GLenum tex);

public:
	int width;
	int height;
	int number_of_channels;

private:
	unsigned int texture;
};

#endif

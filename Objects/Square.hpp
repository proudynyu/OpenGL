#pragma once

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#include "../VertexBuffer.hpp"

class Square {
public:
	Square();
	~Square();

	void Load();
	void UnLoad();
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	//VertexBuffer* VBO;
	//VertexBuffer* EBO;
};

#endif

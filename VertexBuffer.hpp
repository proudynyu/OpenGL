#pragma once

#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <GL/glew.h>

class VertexBuffer {
public:
	unsigned int ID;
	unsigned int bufferSize;
	GLenum target;
	GLenum usage;

public:
	VertexBuffer(unsigned int n, const void* data, GLenum target, GLenum usage);
	~VertexBuffer();
	void Load();
};

#endif

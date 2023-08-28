#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(unsigned int n, const void* data, GLenum target, GLenum usage)
	: bufferSize(n), target(target), usage(usage)
{
	glGenBuffers(n, &ID);
	glBindBuffer(target, ID);
	glBufferData(target, sizeof(data), data, usage);
}

VertexBuffer::~VertexBuffer() 
{
	glDeleteBuffers(bufferSize, &ID);
}

void VertexBuffer::Load() {
	glBindBuffer(target, ID);
}
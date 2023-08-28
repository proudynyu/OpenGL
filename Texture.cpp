#include "Texture.hpp"

Texture::Texture(const char* filename, GLenum format, bool flip_image, GLint param) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, param);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, param);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(flip_image);
	unsigned char* data = stbi_load(filename, &width, &height, &number_of_channels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load the Texture" << std::endl;
	}

	stbi_image_free(data);
}

Texture::~Texture() {}

void Texture::Load(GLenum tex) {
	glActiveTexture(tex);
	glBindTexture(GL_TEXTURE_2D, texture);
}
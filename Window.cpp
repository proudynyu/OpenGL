#include <array>
#include <iostream>

#include "Window.hpp"
#include "Shader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "Texture.hpp"
#include "Objects/Square.hpp"

Window::Window() {}

Window::Window(int width, int height, const char* title)
{
	screenWidth = width;
	screenHeight = height;
	screenTitle = title;
	window = glfwCreateWindow(screenWidth, screenHeight, screenTitle, NULL, NULL);
}

// look somewhere to improve this, this is not in the Window.hpp
auto frameBufferSizeCallback = [](GLFWwindow* window, int w, int h) {
	glViewport(0, 0, w, h);
};

void Window::proccessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	// wireframe
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	// fill
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Window::Init()
{
	glfwMakeContextCurrent(window);
	glewInit();

	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

void Window::Update()
{
	Square square;

	Shader shaderProgram("res/shaders/vertex/vertex_basic.glsl", "res/shaders/fragment/fragment_basic.glsl");

	Texture texture_1("res/textures/container.jpg", GL_RGB, false, GL_CLAMP_TO_EDGE);
	Texture texture_2("res/textures/awesomeface.png", GL_RGBA, true); // png has an alpha channel

	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));

	while (!glfwWindowShouldClose(window))
	{
		proccessInput(window);

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);

		texture_1.Load(GL_TEXTURE0);
		texture_2.Load(GL_TEXTURE1);

		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		unsigned int transformLoc = glGetUniformLocation(shaderProgram.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		shaderProgram.setInt("ourTexture", 0);
		shaderProgram.setInt("texture2", 1);
		shaderProgram.use();
		square.Load();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(shaderProgram.ID); 
	glfwTerminate();
}
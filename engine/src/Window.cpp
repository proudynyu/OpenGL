#include <array>
#include <iostream>

#include "Window.hpp"
#include "Shader.hpp"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GlLogCall(#x, __FILE__, __LINE__))

static void GlClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GlLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ": " << line << std::endl;
		return false;
	}

	return true;
}

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
	float positions[] = {
		// position				// color
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
	};

	// generate a buffer, selecting it, and telling GL what kind of buffer this is it
	// vao - vertex array object
	// vbo - vertex buffer object
	// ebo - element buffer object

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	// vertex position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	// vertex color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	// indices buffers (EBO - vertex buffer object)
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	Shader shaderProgram("res/shaders/vertex/basic.glsl", "res/shaders/fragment/basic.glsl");

	while (!glfwWindowShouldClose(window))
	{
		proccessInput(window);

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.use();
		shaderProgram.setFloat("xOffSet", 0.5f);
		glBindVertexArray(VAO);
		GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram.ID); 
	glfwTerminate();
}

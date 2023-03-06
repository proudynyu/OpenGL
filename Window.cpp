#include "Window.hpp"
#include "Shader.hpp"

Window::Window() {}

Window::Window(int width, int height, const char* title)
{
	screenWidth = width;
	screenHeight = height;
	screenTitle = title;
	window = glfwCreateWindow(screenWidth, screenHeight, screenTitle, NULL, NULL);
}

void Window::Init()
{
	glfwMakeContextCurrent(window);
	glewInit();
}

void Window::Update()
{
	// ======== test ========

	float positions[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	// generate a buffer, selecting it, and telling GL what kind of buffer this is it
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main()\n"
		"{\n"
		"gl_Position = position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;"
		"\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader = Shader::CreateShader(vertexShader, fragmentShader);

	glUseProgram(shader);

	// ======== end test ========

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		// ----
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// ----

		glfwSwapBuffers(window);
	}

	glDeleteProgram(shader);
	glfwTerminate();
}
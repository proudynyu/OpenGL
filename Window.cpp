#include "Window.hpp"

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
	glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(float), NULL);

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

	glfwTerminate();
}
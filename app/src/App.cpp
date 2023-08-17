#include <iostream>
#include "Window.hpp"

int main()
{
	if (!glfwInit())
		return -1;

	Window *window = new Window(800, 600, "OpenGL");

	if (!window) {
		std::cout << "[ERROR]: Error trying to creating a window with GLFW" << std::endl;
		return -1;
	}

	window->Init();
	window->Update();

	return 0;
}
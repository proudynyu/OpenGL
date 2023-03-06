#include "Window.hpp"

int main()
{
	if (!glfwInit())
		return -1;

	Window *window = new Window(800, 600, "OpenGL");

	window->Init();
	window->Update();

	return 0;
}
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Window
{
private:
	int screenWidth = 800;
	int screenHeight = 600;
	const char* screenTitle = "Window";
	GLFWwindow* window = nullptr;

public:
	Window();
	Window(int width, int height, const char* windowTitle);

	void Init();
	void Update();

	void proccessInput(GLFWwindow* window);
};
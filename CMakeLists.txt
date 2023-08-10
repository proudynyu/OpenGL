cmake_minimun_required(VERSION 3.27.1)

project(OpenGL
	LANGUAGE CXX
	VERSION 1.0.0
)

# Executable opengl
add_executable(opengl App.cpp)

# Target directories for include the GLFW and GLEW after they are build it.
target_include_directories(opengl PRIVATE ${CMAKE_SOURCE_DIR}/vendors/glfw/include/GLFW)
target_include_directories(opengl PRIVATE ${CMAKE_SOURCE_DIR}/vendors/glew/include/GL)

set(CMAKE_CXX_STANDARD_11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


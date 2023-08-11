cmake_minimun_required(VERSION 3.27.1)

project(OpenGLProject
	LANGUAGE CXX
	VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectories(app)
add_subdirectories(engine)

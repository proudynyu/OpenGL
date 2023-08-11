cmake_minimun_required(VERSION 3.27.1)

project(OpenGLProject
	LANGUAGE CXX
	VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glew)

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOUCE_DIR}/*.c
    ${CMAKE_SOUCE_DIR}/*.cpp
    )

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOUCE_DIR}/*.h
    ${CMAKE_SOUCE_DIR}/*.hpp
    )

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(OpenGLProject PRIVATE "${PROJECT_SOURCE_DIR}/vendors/glfw/include")
target_include_directories(OpenGLProject PRIVATE "${PROJECT_SOURCE_DIR}/vendors/glew/include")

find_package(OpenGL REQUIRED)
target_link_libraries(OpenGLProject PRIVATE OpenGL::GL)

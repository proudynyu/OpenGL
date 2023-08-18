cmake_minimum_required(VERSION 3.27.1)

project(OpenGLProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(app)
add_subdirectory(engine)

configure_file(res/shaders/fragment/basic.frag res/shaders/fragment/basic.frag COPYONLY)
configure_file(res/shaders/vertex/basic.vertex res/shaders/vertex/basic.vertex COPYONLY)

cmake_minimum_required(VERSION 3.27.1)

project(engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(external/glfw)
add_subdirectory(external/glew)

add_library(${PROJECT_NAME} src/engine.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        glew
        glfw
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC

    PRIVATE
        glew
        glfw
)

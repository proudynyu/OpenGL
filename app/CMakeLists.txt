cmake_minimum_required(VERSION 3.27.1)

project(app VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

set(CMAKE_CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME} engine)
target_include_directories(${PROJECT_NAME} PRIVATE engine)

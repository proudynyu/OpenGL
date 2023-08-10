# OpenGl

This is a study case for OpenGL and to learn CXX with Cmake/Premake.

## Submodules

The submodules are libs that i'm using to access the OpenGL context.
It needs to build each of the libs (see the Readme for each of the libs on how to).

- [GLFW](https://github.com/glfw/glfw.git)
- GLEW

## Init

1. Clone repo

`git clone https://github.com/proudynyu/OpenGL`

2. Initiate the submodules

`git submodule init`

3. Pull the submodules

`git submodule update`

## Build

We are using CMAKE to create the Make files.
You can have a look on the **CMakeLists.txt** to see what is happening.

*Obs: I'm thinking to test the Premake to. Learning one at time*
cmake_minimum_required(VERSION 3.15)
project(Clove)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Clove
Clove.cpp
InputHandlers.cpp
Rectangle.cpp
Renderer.cpp
Shaders.cpp
Square.cpp
)

include_directories(dependencies/include)
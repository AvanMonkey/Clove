cmake_minimum_required(VERSION 3.15)
project(Clove)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lm")
include_directories(HEADER_FILES)
file(GLOB MAIN
    "Clove.cpp"
    "InputHandlers.cpp" 
    "Rectangle.cpp"  
    "Renderer.cpp"
    "Shaders.cpp"
    "Square.cpp"
    )
    add_executable(executable ${MAIN})
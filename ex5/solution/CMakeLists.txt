cmake_minimum_required(VERSION 3.10)
project(ex5_solution CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex5_solution
    assignment1.cpp
    Menu.cpp
    MyQueue.cpp
    Stack.cpp
    StackNode.cpp
)
target_compile_options(ex5_solution PRIVATE -Wall -Wextra)

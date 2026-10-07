cmake_minimum_required(VERSION 3.10)
project(solution CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solution
    main.cpp
    Shape.cpp
    Circle.cpp
    Square.cpp
    OrthogonalTriangle.cpp
)
target_compile_options(solution PRIVATE -Wall -Wextra)

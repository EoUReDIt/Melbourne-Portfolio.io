cmake_minimum_required(VERSION 3.10)
project(Project2)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Automatically gather all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# Create the executable
add_executable(Project2 ${SOURCES}
        binary_operator.h
        unary_operator.h
        ternary.cpp
        quaternary.cpp
        plus.cpp)

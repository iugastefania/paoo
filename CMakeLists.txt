# CMake version
cmake_minimum_required(VERSION 3.2)

set(myproject "MyApp")
# Project name
project(${myproject})

# Define the search path for header files
include_directories(headers)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the executable
add_executable(${PROJECT_NAME}
               headers/Cartof.hpp
               headers/Fruct.hpp
               headers/Leguma.hpp
               headers/Mar.hpp 
               src/Cartof.cpp
               src/Mar.cpp
               src/Leguma.cpp
               src/Fruct.cpp
               src/main.cpp)

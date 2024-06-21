#check version installed: cmake --version
cmake_minimum_required(VERSION 3.18)  # Minimum CMake version required (adjust if needed)
project(hello_cpp)                   # Project name
add_executable(hello hello_cpp.cpp)        # Create an executable named "hello" from "hello_cpp.cpp"
target_compile_options(hello PRIVATE -Wall -Wextra -pedantic)
set(CMAKE_CXX_STANDARD 11)  # Explicitly set C++11 standard
#alternative method
#add_compile_definitions(-Wall -Wextra -pedantic -std=c++11)
#extra flags
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)
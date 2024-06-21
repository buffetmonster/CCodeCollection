#CMake setup:
#sudo apt install cmake #install the tool
#check version installed: cmake --version

#CMakeLists.txt : Define your build env
#For this example
#cmake_minimum_required(VERSION 3.18)       # Minimum CMake version required (adjust if needed)
#project(hello_cpp)                         # Project Directory name
#add_executable(hello hello_cpp.cpp)        # Create an executable named "hello" from "hello_cpp.cpp"
#target_compile_options(hello PRIVATE -Wall -Wextra -pedantic)
#set(CMAKE_CXX_STANDARD 11)  # Explicitly set C++11 standard

#Building the project: (from project directory)
#mkdir build
#cd build
#Run CMake to generate the build system files specific to your compiler 
#cmake ..
#then build
#make
#make clean

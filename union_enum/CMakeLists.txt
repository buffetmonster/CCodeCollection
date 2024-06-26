cmake_minimum_required(VERSION 3.18)
project(union_enum)

# Add executable
add_executable(union_enum union_enum.cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add compile options
target_compile_options(union_enum PRIVATE -Wall -Wextra -pedantic)

#by default disable the gdb flags
#set(CMAKE_BUILD_TYPE Run)

# Add debug-specific flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
  set_target_properties(union_enum PROPERTIES
    COMPILE_FLAGS "-g"
    LINK_FLAGS "-g"
  )
endif()

# Always print the current build type
message(STATUS "Setting to build type: ${CMAKE_BUILD_TYPE}")

# Add a custom target for running the executable
add_custom_target(run
  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/union_enum
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS union_enum
  COMMENT "Running the union_enum executable"
)

# Add a custom target for debugging
add_custom_target(debug
  COMMAND gdb --args ${CMAKE_CURRENT_BINARY_DIR}/union_enum
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS union_enum
  COMMENT "Building and running the union_enum executable in debug mode"
)

#make debug will now run gdb as long as not disabled:: CMAKE_BUILD_TYPE
#or manually 
#gdb ./union_enum
#for valgrind
#valgrind ./union_enum
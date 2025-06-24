# * - Required

cmake_minimum_required(VERSION 3.22) # *; Jammy uses 3.22.1
project(hello_world_cmake) # *

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS) # DEBUG; Saves the commands for manual compilation in a .json file

add_executable(main src/main.cpp) # The working (root) directory of the project is where CMakeLists.txt resides so we have to specify the src files are in the source directory


# * - Required

cmake_minimum_required(VERSION 3.22) # *; Jammy uses 3.22.1
project(hello_world_cmake) # *

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # DEBUG; Saves the commands for manual compilation in a .json file

add_executable(main src/main.cpp) # The working (root) directory of the project is where CMakeLists.txt resides so the relative paths are resolved from there


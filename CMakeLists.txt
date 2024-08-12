cmake_minimum_required(VERSION 3.20)
project(Avalanche LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(AVL_SOURCE_DIR="${CMAKE_SOURCE_DIR}/Avalanche/")
add_compile_definitions(PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}/Sandbox/")

add_subdirectory(Avalanche)
add_subdirectory(Sandbox)
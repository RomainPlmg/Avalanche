cmake_minimum_required(VERSION 3.20)
project(Avalanche)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)

add_subdirectory(Avalanche)
add_subdirectory(Sandbox)
project(Avalanche LANGUAGES C CXX)

add_compile_definitions(AVL_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")

if (WIN32)
    add_definitions(-DAVL_PLATFORM_WINDOWS)
elseif (UNIX)
    add_definitions(-DAVL_PLATFORM_UNIX)
endif (WIN32)
add_definitions(-DAVL_BUILD_DLL)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DAVL_DEBUG -DAVL_ENABLE_ASSERTS)
endif ()

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC
        "src/*.h"
        "src/*.cpp"
        "src/*.c"
)

# Add GLAD to the project
add_subdirectory(${CMAKE_SOURCE_DIR}/Avalanche/vendor/glad)

# Add GLM to the project
add_subdirectory(${CMAKE_SOURCE_DIR}/Avalanche/vendor/GLM)

# Add GLFW to the project
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
add_subdirectory(${CMAKE_SOURCE_DIR}/Avalanche/vendor/GLFW)

add_library(Avalanche SHARED ${SRC})
target_precompile_headers(Avalanche PUBLIC src/avlpch.h)
target_include_directories(Avalanche PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/STB/
)
target_link_libraries(Avalanche PRIVATE ${OPENGL_LIBRARY} glfw glad glm::glm)
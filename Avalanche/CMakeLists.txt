project(Avalanche)

add_definitions(-DAVL_PLATFORM_WINDOWS -DAVL_BUILD_DLL)

file(GLOB_RECURSE SRC
     "src/*.h"
     "src/*.cpp"
     "src/*.c"
)

add_library(Avalanche SHARED ${SRC})
target_include_directories(Avalanche PRIVATE
    ${CMAKE_SOURCE_DIR}/Avalanche/vendor/spdlog/include/
)
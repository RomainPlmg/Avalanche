project(Sandbox)

add_definitions(-DAVL_PLATFORM_WINDOWS)

file(GLOB_RECURSE SRC
     "src/*.h"
     "src/*.cpp"
     "src/*.c"
)

add_executable(Sandbox ${SRC})
target_link_libraries(Sandbox Avalanche)
target_include_directories(Sandbox PRIVATE
    ${CMAKE_SOURCE_DIR}/Avalanche/src/
    ${CMAKE_SOURCE_DIR}/Avalanche/vendor/spdlog/include/
)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:Avalanche>
    $<TARGET_FILE_DIR:Sandbox>
)
cmake_minimum_required(VERSION 3.30)
project(Bezier_Curve_SDL)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(vendor/SDL2)
file(GLOB SOURCES "src/*.cpp" "src/*.h")
add_executable(bezier Main.cpp ${SOURCES})

set(SDL_GFX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2_gfx-1.0.4")

add_custom_target(gfx
    COMMENT "Building SDL2_GFX library"
    COMMAND make
    WORKING_DIRECTORY ${SDL_GFX_DIR}
)
target_link_libraries(bezier PRIVATE SDL2::SDL2)

target_include_directories(bezier PRIVATE ${SDL_GFX_DIR})

add_dependencies(bezier gfx)

find_library(GFX_LIB NAMES SDL2_gfx HINTS ${SDL_GFX_DIR}/.libs)


if (NOT GFX_LIB)
    message(FATAL_ERROR "SDL2_gfx library not found!")
endif()

target_link_libraries(bezier PRIVATE ${GFX_LIB})



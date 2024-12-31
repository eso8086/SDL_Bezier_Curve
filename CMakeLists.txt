cmake_minimum_required(VERSION 3.14)
project(Bezier_Curve_SDL)
set(CMAKE_CXX_STANDARD 14)

option(USE_VENDOR_SDL "Use vendored SDL libraries" ON)

if(USE_VENDOR_SDL)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()


file(GLOB GFX_SOURCES "vendor/SDL2_gfx-1.0.4/*.c")
add_library(SDL2_gfx SHARED ${GFX_SOURCES})

target_link_libraries(SDL2_gfx PRIVATE SDL2::SDL2)

file(GLOB SOURCES "src/*.cpp")
add_executable(Bezier Main.cpp ${SOURCES})

target_include_directories(Bezier PRIVATE vendor/SDL2_gfx-1.0.4 src)

if(TARGET SDL2::SDL2main)
    target_link_libraries(Bezier PRIVATE SDL2::SDL2main)
endif()


target_link_libraries(Bezier PRIVATE SDL2::SDL2 SDL2_gfx)
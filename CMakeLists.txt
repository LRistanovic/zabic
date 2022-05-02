cmake_minimum_required(VERSION 3.21)
project(zabic)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_library(zabic STATIC ${sources})

target_link_libraries(zabic /usr/lib/libSDL2-2.0.so libSDL2_image.so)

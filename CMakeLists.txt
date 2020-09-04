cmake_minimum_required(VERSION 3.15)
project(locke-lang)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

add_subdirectory(library)
add_subdirectory(compiler)
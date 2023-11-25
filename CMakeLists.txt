cmake_minimum_required(VERSION 3.28)
project(ide-test VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(ClangLibcxxModules)

add_executable(ide-test
        main.cpp
        literals.cpp
        source_loc.cpp)

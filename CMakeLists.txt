cmake_minimum_required(VERSION 3.30)

project(ide-test VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED YES)


add_executable(ide-test
        main.cpp
        no_module.cpp
        literals.cpp
        source_loc.cpp)

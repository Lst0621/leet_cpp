cmake_minimum_required(VERSION 3.10)
project(leet)

SET (CMAKE_C_COMPILER /usr/bin/clang)
SET (CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
include_directories(include)
add_subdirectory(test)


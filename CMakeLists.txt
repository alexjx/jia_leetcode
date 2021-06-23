cmake_minimum_required(VERSION 3.10)
project(leetcode)
set(CMAKE_CXX_STANDARD 17)

# googletest
include(GoogleTest)
enable_testing()
find_package(Threads REQUIRED)

# tests
add_subdirectory(challenges)
add_subdirectory(practices)

cmake_minimum_required(VERSION 3.5)

project(MaxSubStr LANGUAGES CXX)

enable_testing()

find_package(Boost REQUIRED)

add_subdirectory(src solution)
add_subdirectory(test tests)

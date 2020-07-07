cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../include)

find_package(Boost COMPONENTS system unit_test_framework REQUIRED)

add_executable(tests ../src/solution.cpp solution_test.cpp)

add_test(NAME tests COMMAND tests)

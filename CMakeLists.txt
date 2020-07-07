cmake_minimum_required(VERSION 3.5)

project(MaxSubStr LANGUAGES CXX)

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
#        ${PROJECT_BINARY_DIR}/bin
#        CACHE PATH
#        "Single Directory for all"
#    )

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
#        ${PROJECT_BINARY_DIR}/bin
#        CACHE PATH
#        "Single Directory for all"
#    )

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
#        ${PROJECT_BINARY_DIR}/lib
#        CACHE PATH
#        "Single Directory for all"
#    )

enable_testing()

find_package(Boost REQUIRED)

add_subdirectory( src build/src )
add_subdirectory( test build/test )

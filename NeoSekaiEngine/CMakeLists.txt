cmake_minimum_required(VERSION 3.0)
project(SekaiEngine)

option(RUN_TEST "RUN_TEST" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

add_subdirectory(./engine)
add_subdirectory(./sandbox)
if(${RUN_TEST})
    add_subdirectory(./test)
endif()
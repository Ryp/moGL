cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(moGL)
enable_testing()

# Avoid source tree pollution
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(WARNING "In-source builds are not encouraged. Make a separate folder for building:\nmkdir build; cd build; cmake ..;cd ..\nBefore that, remove the files already created:\nrm -rf CMakeCache.txt CMakeFiles")
endif()

# Force CMAKE_BUILD_TYPE
if(CMAKE_BUILD_TYPE STREQUAL "")
    message(WARNING "Please specify a build type\nExample: cmake .. -DCMAKE_BUILD_TYPE=Debug")
endif()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

option(MOGL_BUILD_TESTS "build-tests" ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

list(APPEND CMAKE_CXX_FLAGS ${CXX11_FLAGS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${moGL_BINARY_DIR}/test)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${moGL_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${moGL_BINARY_DIR}/lib)

if(MOGL_BUILD_TESTS)
    add_subdirectory(test)
endif()

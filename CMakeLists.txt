cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(moGL)

# Avoid source tree pollution
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(WARNING "In-source builds are not encouraged. Make a separate folder for building:\nmkdir build; cd build; cmake ..;cd ..\nBefore that, remove the files already created:\nrm -rf CMakeCache.txt CMakeFiles")
endif(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)

# Force CMAKE_BUILD_TYPE
if(CMAKE_BUILD_TYPE STREQUAL "")
    message(WARNING "Please specify a build type\nExample: cmake .. -DCMAKE_BUILD_TYPE=Debug")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(CXX11 REQUIRED)
find_package(OpenGL REQUIRED)

list(APPEND CMAKE_CXX_FLAGS ${CXX11_FLAGS})

add_subdirectory(src)

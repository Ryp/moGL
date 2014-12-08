cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)

project(moGL)
option(MOGL_BUILD_TESTS "build-tests" OFF)

install(DIRECTORY mogl DESTINATION include FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY mogl DESTINATION include FILES_MATCHING PATTERN "*.inl")
install(DIRECTORY cmake DESTINATION share/mogl FILES_MATCHING PATTERN "*.cmake")

if(MOGL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(moGL)
enable_testing()

option(MOGL_BUILD_TESTS "build-tests" ON)

# FIXME Does not preserve subdirectories
file(GLOB_RECURSE MOGL_CMAKE    "${CMAKE_CURRENT_SOURCE_DIR}/mogl/cmake/*.cmake")
file(GLOB_RECURSE MOGL_INLINE   "${CMAKE_CURRENT_SOURCE_DIR}/mogl/*.inl")
file(GLOB_RECURSE MOGL_HEADER   "${CMAKE_CURRENT_SOURCE_DIR}/mogl/*.hpp")

install(FILES ${MOGL_CMAKE} DESTINATION share)
install(FILES ${MOGL_INLINE} DESTINATION include)
install(FILES ${MOGL_HEADER} DESTINATION include)

if(MOGL_BUILD_TESTS)
    add_subdirectory(test)
endif()

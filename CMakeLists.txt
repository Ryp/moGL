cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(moGL)
enable_testing()

option(MOGL_BUILD_TESTS "build-tests" ON)

file(GLOB_RECURSE MOGL_CMAKE mogl/cmake/*.cmake)
file(GLOB_RECURSE MOGL_INLINE mogl/*.inl)
file(GLOB_RECURSE MOGL_HEADER mogl/*.hpp)

install(FILES ${MOGL_CMAKE} DESTINATION share)
install(FILES ${MOGL_INLINE} DESTINATION include)
install(FILES ${MOGL_HEADER} DESTINATION include)

if(MOGL_BUILD_TESTS)
    add_subdirectory(test)
endif()

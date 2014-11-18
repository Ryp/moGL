cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)

project(moGL)
enable_testing()
option(MOGL_BUILD_TESTS "build-tests" OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(CXX11 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")
find_package(OpenGL REQUIRED)

set(MOGL_LIB mogl)
set(MOGL_SRCS
    mogl/queryobject.cpp
    mogl/buffer/bufferobject.cpp
    mogl/framebuffer/framebufferfunctions.cpp
    mogl/framebuffer/framebufferobject.cpp
    mogl/renderbuffer/renderbufferobject.cpp
    mogl/shader/shaderobject.cpp
    mogl/shader/shaderprogram.cpp
    mogl/texture/textureobject.cpp
)

add_library(${MOGL_LIB} SHARED ${MOGL_SRCS})

#Set compilation flags
set(MOGL_COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(MOGL_COMPILE_FLAGS "${MOGL_COMPILE_FLAGS} -Wall -Wextra -Wshadow -Wundef")
endif()
set_target_properties(${MOGL_LIB} PROPERTIES COMPILE_FLAGS "${MOGL_COMPILE_FLAGS}")

#User includes dirs (won't hide warnings)
target_include_directories(${MOGL_LIB} PUBLIC
    ${CMAKE_SOURCE_DIR})

#External includes dirs (won't show warnings)
# target_include_directories(${MOGL_LIB} SYSTEM PUBLIC
# )

#Libraries
# target_link_libraries(${MOGL_LIB}
# )

install(DIRECTORY mogl DESTINATION include FILES_MATCHING PATTERN "*.hpp")
install(TARGETS ${MOGL_LIB} DESTINATION lib)
install(DIRECTORY cmake DESTINATION share/mogl FILES_MATCHING PATTERN "FindMoGL*.cmake") # FIXME

if(MOGL_BUILD_TESTS)
    add_subdirectory(test)
endif()

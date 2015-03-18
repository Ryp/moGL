find_package(OpenGL REQUIRED)
find_package(glbinding REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

set(EXAMPLE_BIN example)

set(EXAMPLE_SRCS
    ${CMAKE_SOURCE_DIR}/common/glcontext.cpp
    main.cpp
    ImageLoader.cpp
    Model.cpp
    ModelLoader.cpp
)

add_executable(${EXAMPLE_BIN} ${EXAMPLE_SRCS})

#Set compilation flags
set(EXAMPLE_COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(EXAMPLE_COMPILE_FLAGS "${EXAMPLE_COMPILE_FLAGS} -Wall -Wextra -Wshadow -Wundef")
endif()
set_target_properties(${EXAMPLE_BIN} PROPERTIES
    CXX_STANDARD 14
    COMPILE_FLAGS "${EXAMPLE_COMPILE_FLAGS}")

#User includes dirs (won't hide warnings)
target_include_directories(${EXAMPLE_BIN} PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

#External includes dirs (won't show warnings)
target_include_directories(${EXAMPLE_BIN} SYSTEM PUBLIC
    ${OPENGL_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${GLBINDING_INCLUDES}
)

#Libraries
target_link_libraries(${EXAMPLE_BIN}
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLBINDING_LIBRARIES}
)

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

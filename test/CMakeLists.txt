list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../mogl/cmake)
find_package(MoGL REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(CXX11 REQUIRED)

find_package(OpenGL REQUIRED)
find_package(glfw REQUIRED)
find_package(GLEW REQUIRED)

list(APPEND CMAKE_CXX_FLAGS ${CXX11_FLAGS})
list(APPEND MOGL_EXAMPLE_INCLUDE_DIRS ${MOGL_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR})

set(MOGL_COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(MOGL_COMPILE_FLAGS "${MOGL_COMPILE_FLAGS} -Wall -Wextra -Wshadow -Wundef")
endif()

function(moglCreateTest NAME)
    if(MOGL_BUILD_TESTS)
        set(TEST_NAME test-${NAME})
        add_executable(${TEST_NAME} ${NAME}.cpp glcontext.cpp)
        set_target_properties(${TEST_NAME} PROPERTIES
            COMPILE_FLAGS "${MOGL_COMPILE_FLAGS}"
            INCLUDE_DIRECTORIES "${MOGL_EXAMPLE_INCLUDE_DIRS}")
        target_link_libraries(${TEST_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARY})
        add_test(NAME ${TEST_NAME}
            COMMAND $<TARGET_FILE:${TEST_NAME}>)
    endif()
endfunction()

moglCreateTest(shader_program)
moglCreateTest(framebuffer)

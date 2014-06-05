
find_package(CXX11 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw REQUIRED)
find_package(GLEW REQUIRED)

list(APPEND MOGL_EXAMPLE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR})

list(APPEND CMAKE_CXX_FLAGS ${CXX11_FLAGS})

function(moglCreateTest NAME)
    if(MOGL_BUILD_TESTS)
        set(TEST_NAME test-${NAME})
        add_executable(${TEST_NAME} ${NAME}.cpp glcontext.cpp)
        set_target_properties(${TEST_NAME} PROPERTIES
            INCLUDE_DIRECTORIES "${MOGL_EXAMPLE_INCLUDE_DIRS}")
        target_link_libraries(${TEST_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARY})
        add_test(
            NAME ${TEST_NAME}
            COMMAND $<TARGET_FILE:${TEST_NAME}>)
    endif()
endfunction()

moglCreateTest(shader_program)

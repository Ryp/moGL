
function(moglCreateTest NAME)
    if(MOGL_BUILD_TESTS)
        set(TEST_NAME test-${NAME})
        add_executable(${TEST_NAME} ${NAME}.cpp)
        set_target_properties(${TEST_NAME}
            PROPERTIES
            INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/src)
        target_link_libraries(${TEST_NAME} mogl GLEW)
        add_test(
            NAME ${TEST_NAME}
            COMMAND $<TARGET_FILE:${TEST_NAME}>)
    endif()
endfunction()

moglCreateTest(shader_program)

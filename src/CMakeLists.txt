set(MOGL_LIB mogl)

set(MOGL_SRCS
    shader/shaderobject.cpp
    shader/shaderprogram.cpp
)

add_library(${MOGL_LIB} SHARED ${MOGL_SRCS})

set(OSAC_COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")

# Add debug flags
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
        set(MOGL_COMPILE_FLAGS "${MOGL_COMPILE_FLAGS} -Wall -Wextra -Wshadow -Wundef")
    endif()
endif()

#Set compilation flags for current target
set_target_properties(${MOGL_LIB} PROPERTIES
    COMPILE_FLAGS "${MOGL_COMPILE_FLAGS}"
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${MOGL_LIB} ${OPENGL_LIBRARIES})

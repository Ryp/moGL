#===============================================================================
# Modern OpenGL Wrapper
#
# Author: Thibault Schueller <ryp.sqrt@gmail.com>
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#===============================================================================

# FindMoGL.cmake      - attempts to locate the mogl library.
#
# This module defines the following variables (on success):
#   MOGL_FOUND        - if the library was successfully located
#   MOGL_INCLUDE_DIRS - where to find mogl/mogl.hpp
#   MOGL_LIBRARIES    - required mogl libraries

find_package(PkgConfig)

set(MOGL_HEADER_SEARCH_DIRS
    ".." # For tests only
    "/usr/include"
    "/usr/local/include")

set(MOGL_LIB_SEARCH_DIRS
    "../build" # For tests only
    "/usr/lib/mogl"
    "/usr/local/lib/mogl")

find_path(MOGL_INCLUDE_DIR "mogl/mogl.hpp"
    PATHS ${MOGL_HEADER_SEARCH_DIRS})

find_library(MOGL_LIBRARY NAMES libmogl.so
    PATHS ${MOGL_LIB_SEARCH_DIRS})

set(MOGL_LIBRARIES ${MOGL_LIBRARY})
set(MOGL_INCLUDE_DIRS ${MOGL_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MoGL DEFAULT_MSG MOGL_INCLUDE_DIR MOGL_LIBRARY)
mark_as_advanced(MOGL_INCLUDE_DIR MOGL_LIBRARY)

#===============================================================================
# Modern OpenGL Wrapper
#
# Author: Thibault Schueller <ryp.sqrt@gmail.com>
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#===============================================================================

# FindMoGL            - attempts to locate the mogl library.
#
# This module defines the following variables (on success):
#   MOGL_INCLUDE_DIRS - where to find mogl/mogl.hpp
#   MOGL_FOUND        - if the library was successfully located

include(FindPackageHandleStandardArgs)

set(MOGL_HEADER_SEARCH_DIRS
    ".." # For tests only
    "/usr/include"
    "/usr/local/include")

find_path(MOGL_INCLUDE_DIR "mogl/mogl.hpp"
    PATHS ${MOGL_HEADER_SEARCH_DIRS})

set(MOGL_INCLUDE_DIRS "${MOGL_INCLUDE_DIR}")

find_package_handle_standard_args(MoGL DEFAULT_MSG MOGL_INCLUDE_DIRS)
mark_as_advanced(MOGL_INCLUDE_DIRS)

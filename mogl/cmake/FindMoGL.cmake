# FindMoGL            - attempts to locate the mogl library.
#
# This module defines the following variables (on success):
#   MOGL_INCLUDE_DIRS - where to find mogl/mogl.hpp
#   MOGL_FOUND        - if the library was successfully located
#
#=============================================================================
# Modern OpenGL Wrapper
#
# Copyright (c) 2014 Thibault Schueller
# This file is distributed under the MIT License
#
# Author: Thibault Schueller <ryp.sqrt@gmail.com>
#=============================================================================

include(FindPackageHandleStandardArgs)

set(MOGL_HEADER_SEARCH_DIRS
    "/usr/include"
    "/usr/local/include"
    "..")

find_path(MOGL_INCLUDE_DIR "mogl/mogl.hpp"
    PATHS ${MOGL_HEADER_SEARCH_DIRS})

set(MOGL_INCLUDE_DIRS "${MOGL_INCLUDE_DIR}")

find_package_handle_standard_args(MoGL DEFAULT_MSG MOGL_INCLUDE_DIRS)
mark_as_advanced(MOGL_INCLUDE_DIRS)

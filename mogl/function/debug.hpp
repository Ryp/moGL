////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file debug.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_DEBUG_INCLUDED
#define MOGL_DEBUG_INCLUDED

#include <sstream>
#include <stdexcept>

namespace mogl
{
    namespace Debug
    {
        std::string getErrorString(GLenum error);
        void        assertGLState(const char* file, const char* func, int line);
    };
}

#define MOGL_ASSERT_GLSTATE() mogl::Debug::assertGLState(__FILE__, __FUNCTION__, __LINE__)

#include "debug.inl"

#endif // MOGL_DEBUG_INCLUDED

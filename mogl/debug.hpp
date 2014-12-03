////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2014 Thibault Schueller
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
    class Debug
    {
    public:
        Debug() = delete;

    public:
        static std::string  getErrorString(GLenum error);
        static void         assertGLState(const char* file, const char* func, int line);
    };
}

#define MOGL_ASSERT() mogl::Debug::assertGLState(__FILE__, __FUNCTION__, __LINE__)

#include "debug.inl"

#endif // MOGL_DEBUG_INCLUDED

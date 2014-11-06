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
        static void assertGLState(const char* file, const char* func, int line)
        {
            std::ostringstream  stream;
            std::string         errorDescription;
            GLenum              errorNo;

            if ((errorNo = glGetError()) != GL_NO_ERROR)
            {
                switch (errorNo) {
                    case GL_INVALID_ENUM:                   errorDescription = "Invalid enum"; break;
                    case GL_INVALID_VALUE:                  errorDescription = "Invalid value"; break;
                    case GL_INVALID_OPERATION:              errorDescription = "Invalid operation"; break;
                    case GL_INVALID_FRAMEBUFFER_OPERATION:  errorDescription = "Invalid framebuffer operation"; break;
                    case GL_OUT_OF_MEMORY:                  errorDescription = "Out of memory"; break;
                    case GL_STACK_UNDERFLOW:                errorDescription = "Stack underflow"; break;
                    case GL_STACK_OVERFLOW:                 errorDescription = "Stack overflow"; break;
                    default:                                errorDescription = "Unknown error"; break;
                }
                stream << file << ':' << line << ": in '" << func << "': (" << errorNo << ") " << errorDescription;
                throw (std::runtime_error(stream.str()));
            }
        }
    };
}

#define MOGL_ASSERT() mogl::Debug::assertGLState(__FILE__, __FUNCTION__, __LINE__)

#endif // MOGL_DEBUG_INCLUDED

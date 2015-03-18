////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file debug.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include <mogl/exception/moglexception.hpp>

#include <sstream>

namespace mogl
{
    namespace Debug
    {
        inline std::string getErrorString(GLenum error)
        {
            switch (error) {
                case GL_INVALID_ENUM:                   return "Invalid enum";
                case GL_INVALID_VALUE:                  return "Invalid value";
                case GL_INVALID_OPERATION:              return "Invalid operation";
                case GL_INVALID_FRAMEBUFFER_OPERATION:  return "Invalid framebuffer operation";
                case GL_OUT_OF_MEMORY:                  return "Out of memory";
                case GL_STACK_UNDERFLOW:                return "Stack underflow";
                case GL_STACK_OVERFLOW:                 return "Stack overflow";
                default:                                return "Unknown error";
            }
        }

        inline void assertGLState(const char* file, const char* func, int line)
        {
            std::ostringstream  stream;
            std::string         errorDescription;
            GLenum              errorNo = glGetError();

            if (errorNo != GL_NO_ERROR)
            {
                errorDescription = getErrorString(errorNo);
                stream << file << ':' << line << ": in '" << func << "': (" << errorNo << ") " << errorDescription;
                throw (mogl::MoGLException(stream.str()));
            }
        }
    }
}

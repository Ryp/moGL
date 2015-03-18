////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file handle.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
///
/// @brief GL Handle wrapper, base class to most mogl objects, templated on
/// the handle type, because it is not always GLuint (sometimes GLsync).
/// The isValid() method will result to a call to glIs*() with the appropriated
/// name.
///
/// Ex: class FrameBuffer -> isValid will call glIsFramebuffer().
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_HANDLE_INCLUDED
#define MOGL_HANDLE_INCLUDED

namespace mogl
{
    template <class T = GLuint>
    class Handle
    {
    public:
        Handle(GLenum identifier = GL_NONE) : _handle(0), _identifier(identifier) {}
        virtual ~Handle() = default;

        Handle(const Handle& other) = delete;
        Handle& operator=(const Handle& other) = delete;

        Handle(Handle&& other) noexcept : _handle(other._handle), _identifier(other._identifier)
        {
            other._handle = 0;
        }

    public:
        T   getHandle() const { return _handle; }

    public:
        virtual bool    isValid() const = 0;

    protected:
        T               _handle;
        const GLenum    _identifier;
    };
}

#endif // MOGL_HANDLE_INCLUDED

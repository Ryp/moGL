////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sync.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_SYNC_INCLUDED
#define MOGL_SYNC_INCLUDED

namespace mogl
{
    namespace Sync
    {
        static void flush();
        static void finish();
    };
}

#include "sync.inl"

#endif // MOGL_SYNC_INCLUDED

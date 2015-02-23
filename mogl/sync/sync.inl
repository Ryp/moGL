////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sync.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "sync.hpp"

namespace mogl
{
    namespace Sync
    {
        void finish()
        {
            glFinish();
        }

        void flush()
        {
            glFlush();
        }
    }
}

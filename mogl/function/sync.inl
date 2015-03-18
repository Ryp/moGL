////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file sync.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    namespace Sync
    {
        inline void finish()
        {
            glFinish();
        }

        inline void flush()
        {
            glFlush();
        }
    }
}

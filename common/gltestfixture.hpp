////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file gltestfixture.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_GLTESTFIXTURE_INCLUDED
#define MOGL_GLTESTFIXTURE_INCLUDED

#include "glcontext.hpp"
#include "gtest/gtest.h"

class GLTestFixture : public ::testing::Test
{
public:
    void SetUp() override;
    void TearDown() override;

protected:
    GLContext   _ctx;
};

#endif // MOGL_GLTESTFIXTURE_INCLUDED

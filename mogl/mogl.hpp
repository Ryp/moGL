////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file mogl.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_INCLUDED
#define MOGL_INCLUDED

#include <mogl/exception/moglexception.hpp>
#include <mogl/exception/shaderexception.hpp>

#include <mogl/function/debug.hpp>
#include <mogl/function/states.hpp>
#include <mogl/function/sync.hpp>

#include <mogl/object/buffer/arraybuffer.hpp>
#include <mogl/object/buffer/atomiccounterbuffer.hpp>
#include <mogl/object/buffer/buffer.hpp>
#include <mogl/object/buffer/elementarraybuffer.hpp>
#include <mogl/object/buffer/shaderstoragebuffer.hpp>
#include <mogl/object/buffer/transformfeedbackbuffer.hpp>
#include <mogl/object/buffer/uniformbuffer.hpp>
#include <mogl/object/fence.hpp>
#include <mogl/object/framebuffer.hpp>
#include <mogl/object/handle.hpp>
#include <mogl/object/query.hpp>
#include <mogl/object/renderbuffer.hpp>
#include <mogl/object/sampler.hpp>
#include <mogl/object/shader/programpipeline.hpp>
#include <mogl/object/shader/shader.hpp>
#include <mogl/object/shader/shaderprogram.hpp>
#include <mogl/object/texture.hpp>
#include <mogl/object/transformfeedback.hpp>
#include <mogl/object/vertexarray.hpp>

#include <mogl/version.hpp>

#endif // MOGL_INCLUDED

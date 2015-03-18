////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file programpipeline.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef MOGL_PROGRAMPIPELINE_INCLUDED
#define MOGL_PROGRAMPIPELINE_INCLUDED

#include <mogl/object/handle.hpp>

namespace mogl
{
    class ProgramPipeline : public Handle<GLuint>
    {
    public:
        ProgramPipeline();
        ~ProgramPipeline();

        ProgramPipeline(const ProgramPipeline& other) = delete;
        ProgramPipeline& operator=(const ProgramPipeline& other) = delete;

    public:
        void    useStages(GLbitfield stages, GLuint program);
        void    setActiveProgram(GLuint program);
        void    validate();
        void    get(GLenum property, GLint* value); // Direct call to glGetProgramPipelineiv()
        GLint   get(GLenum property);
        bool    isValid() const override final;
        // TODO add glGetProgramPipelineInfoLog() call
    };
}

#include "programpipeline.inl"

#endif // MOGL_PROGRAMPIPELINE_INCLUDED

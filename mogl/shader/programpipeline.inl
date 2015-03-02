////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file programpipeline.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

namespace mogl
{
    inline ProgramPipeline::ProgramPipeline()
    {
        glCreateProgramPipelines(1, &_handle);
    }

    inline ProgramPipeline::~ProgramPipeline()
    {
        glDeleteProgramPipelines(1, &_handle);
    }

    inline void ProgramPipeline::useStages(GLbitfield stages, GLuint program)
    {
        glUseProgramStages(_handle, static_cast<UseProgramStageMask>(stages), program); // TODO Find solution to remove glbinding dependance
    }

    inline void ProgramPipeline::setActiveProgram(GLuint program)
    {
        glActiveShaderProgram(_handle, program);
    }

    inline void ProgramPipeline::validate()
    {
        glValidateProgramPipeline(_handle);
    }

    inline void ProgramPipeline::get(GLenum property, GLint* value)
    {
        glGetProgramPipelineiv(_handle, property, value);
    }

    inline GLint ProgramPipeline::get(GLenum property)
    {
        GLint   value;
        glGetProgramPipelineiv(_handle, property, &value);
        return value;
    }

    inline bool ProgramPipeline::isValid() const
    {
        return glIsProgramPipeline(_handle) == GL_TRUE;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file shaderprogram.inl
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "shaderprogram.hpp"
#include "mogl/exception.hpp"

#include <iostream>
#include <iomanip>

namespace mogl
{
    inline ShaderProgram::ShaderProgram()
    {
        _handle = glCreateProgram();
        if (!_handle)
            throw(mogl::MoGLException("Could not create shader program"));
    }

    inline ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(_handle);
    }

    inline bool ShaderProgram::isValid() const
    {
        return glIsProgram(_handle) == GL_TRUE;
    }

    inline void ShaderProgram::attach(const ShaderObject& object)
    {
        glAttachShader(_handle, object.getHandle());
    }

    inline void ShaderProgram::detach(const ShaderObject& object)
    {
        glDetachShader(_handle, object.getHandle());
    }

    inline void ShaderProgram::bindAttribLocation(GLuint location, const std::string& attribute)
    {
        glBindAttribLocation(_handle, location, attribute.c_str());
    }

    inline bool ShaderProgram::link()
    {
        GLint       success;
        GLint       logLength = 0;

        glLinkProgram(_handle);
        glGetProgramiv(_handle, GL_LINK_STATUS, &success);
        if (success == static_cast<GLint>(GL_FALSE))
        {
            glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &logLength);
            if (logLength > 1)
            {
                std::vector<GLchar> infoLog(logLength);
                glGetProgramInfoLog(_handle, logLength, &logLength, &infoLog[0]);
                infoLog[logLength - 1] = '\0'; // Overwrite endline
                _log = &infoLog[0];
            }
            glDeleteProgram(_handle);
            return false;
        }
        retrieveLocations();
        //FIXME
        retrieveSubroutines(ShaderObject::ShaderType::VertexShader);
        retrieveSubroutines(ShaderObject::ShaderType::GeometryShader);
        retrieveSubroutines(ShaderObject::ShaderType::TesselationControlShader);
        retrieveSubroutines(ShaderObject::ShaderType::TesselationEvaluationShader);
        retrieveSubroutines(ShaderObject::ShaderType::ComputeShader);
        retrieveSubroutines(ShaderObject::ShaderType::FragmentShader);
        _log = std::string();
        return true;
    }

    inline void ShaderProgram::use()
    {
        if (!_handle)
            throw (mogl::ShaderException("Invalid shader program"));
        glUseProgram(_handle);
    }

    inline const std::string& ShaderProgram::getLog() const
    {
        return _log;
    }

    inline GLuint ShaderProgram::getAttribLocation(const std::string& name) const
    {
        std::map<std::string, GLuint>::const_iterator it;

        if ((it = _attribs.find(name)) != _attribs.end())
            return it->second;
        std::cerr << "Shader attribute \'" << name << "\' does not exist" << std::endl;
        return -1;
    }

    inline GLuint ShaderProgram::getUniformLocation(const std::string& name) const
    {
        std::map<std::string, GLuint>::const_iterator it;

        if ((it = _uniforms.find(name)) != _uniforms.end())
            return it->second;
        std::cerr << "Shader uniform \'" << name << "\' does not exist" << std::endl;
        return -1;
    }

    inline void ShaderProgram::printDebug()
    {
        std::cout << "Attributes:" << std::endl;
        for (auto attrib : _attribs)
            std::cout << std::setw(6) << attrib.second << ": " << attrib.first << std::endl;
        std::cout << "Uniforms:" << std::endl;
        for (auto uniform : _uniforms)
            std::cout << std::setw(6)  << uniform.second << ": " << uniform.first << std::endl;
        for (auto subroutineMap : _subroutines)
        {
            std::cout << "Subroutines for shader idx: " << static_cast<int>(subroutineMap.first) << std::endl;
            for (auto subroutineUniform : subroutineMap.second)
            {
                std::cout << "Subroutine uniform id=" << subroutineUniform.second.uniform << ": " << subroutineUniform.first << std::endl;
                for (auto subroutine : subroutineUniform.second.subroutines)
                    std::cout << "Subroutine id=" << subroutine.second << ": " << subroutine.first << std::endl;
            }
        }
    }

    inline void ShaderProgram::retrieveLocations()
    {
        GLint       n, maxLen;
        GLint       size, location;
        GLsizei     written;
        GLenum      type;
        GLchar*     name;
        std::string uniformName;
        std::string arraySuffix("[0]");

        glGetProgramiv(_handle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLen);
        glGetProgramiv(_handle, GL_ACTIVE_ATTRIBUTES, &n);
        name = new GLchar[maxLen];
        for (int i = 0; i < n; ++i)
        {
            glGetActiveAttrib(_handle, i, maxLen, &written, &size, &type, name);
            location = glGetAttribLocation(_handle, name);
            _attribs[name] = location;
        }
        delete[] name;
        glGetProgramiv(_handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
        glGetProgramiv(_handle, GL_ACTIVE_UNIFORMS, &n);
        name = new GLchar[maxLen];
        for (int i = 0; i < n; ++i)
        {
            glGetActiveUniform(_handle, i, maxLen, &written, &size, &type, name);
            location = glGetUniformLocation(_handle, name);
            uniformName = name;
            _uniforms[uniformName] = location;
            // If the uniform is an array, add the name stripped of its '[0]' suffix
            if (std::mismatch(arraySuffix.rbegin(),arraySuffix.rend(), uniformName.rbegin()).first == arraySuffix.rend())
                _uniforms[uniformName.substr(0, uniformName.length() - arraySuffix.length())] = location;
        }
        delete[] name;
    }

    inline void ShaderProgram::retrieveSubroutines(ShaderObject::ShaderType type)
    {
        GLenum  shaderType = static_cast<GLenum>(type);
        int     countActiveSU;
        char    sname[256]; // FIXME
        int     len;
        int     numCompS;

        glGetProgramStageiv(_handle, shaderType, GL_ACTIVE_SUBROUTINE_UNIFORMS, &countActiveSU);
        for (int i = 0; i < countActiveSU; ++i)
        {
            glGetActiveSubroutineUniformName(_handle, shaderType, i, 256, &len, sname);
            glGetActiveSubroutineUniformiv(_handle, shaderType, i, GL_NUM_COMPATIBLE_SUBROUTINES, &numCompS);
            SubroutineUniform& subUniform = _subroutines[type][sname];

            subUniform.uniform = i;
            GLint* s = new GLint[numCompS];
            glGetActiveSubroutineUniformiv(_handle, shaderType, i, GL_COMPATIBLE_SUBROUTINES, s);
            for (int j = 0; j < numCompS; ++j)
            {
                glGetActiveSubroutineName(_handle, shaderType, s[j], 256, &len, sname);
                subUniform.subroutines[sname] = s[j];
            }
            delete[] s;
        }
    }

    inline void ShaderProgram::setVertexAttribPointer(GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointerOffset)
    {
        glVertexAttribPointer(location, size, type, normalized, stride, pointerOffset);
    }

    inline void ShaderProgram::setVertexAttribPointer(const std::string& name, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointerOffset)
    {
        glVertexAttribPointer(getAttribLocation(name), size, type, normalized, stride, pointerOffset);
    }

    /*
     * GLfloat uniform specialization
     */

    template <>
    inline void ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1)
    {
        glUniform1f(getUniformLocation(name), v1);
    }

    template <>
    inline void ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2)
    {
        glUniform2f(getUniformLocation(name), v1, v2);
    }

    template <>
    inline void ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2, GLfloat v3)
    {
        glUniform3f(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    inline void ShaderProgram::setUniform<GLfloat>(const std::string& name, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4)
    {
        glUniform4f(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLint uniform specialization
     */

    template <>
    inline void ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1)
    {
        glUniform1i(getUniformLocation(name), v1);
    }

    template <>
    inline void ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2)
    {
        glUniform2i(getUniformLocation(name), v1, v2);
    }

    template <>
    inline void ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2, GLint v3)
    {
        glUniform3i(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    inline void ShaderProgram::setUniform<GLint>(const std::string& name, GLint v1, GLint v2, GLint v3, GLint v4)
    {
        glUniform4i(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLuint uniform specialization
     */

    template <>
    inline void ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1)
    {
        glUniform1ui(getUniformLocation(name), v1);
    }

    template <>
    inline void ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2)
    {
        glUniform2ui(getUniformLocation(name), v1, v2);
    }

    template <>
    inline void ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2, GLuint v3)
    {
        glUniform3ui(getUniformLocation(name), v1, v2, v3);
    }

    template <>
    inline void ShaderProgram::setUniform<GLuint>(const std::string& name, GLuint v1, GLuint v2, GLuint v3, GLuint v4)
    {
        glUniform4ui(getUniformLocation(name), v1, v2, v3, v4);
    }

    /*
     * GLfloat uniform array specialization
     */

    template <>
    inline void ShaderProgram::setUniformPtr<1, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform1fv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<2, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform2fv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<3, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform3fv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<4, GLfloat>(const std::string& name, const GLfloat* ptr, GLsizei count)
    {
        glUniform4fv(getUniformLocation(name), count, ptr);
    }

    /*
     * GLint uniform array specialization
     */

    template <>
    inline void ShaderProgram::setUniformPtr<1, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform1iv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<2, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform2iv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<3, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform3iv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<4, GLint>(const std::string& name, const GLint* ptr, GLsizei count)
    {
        glUniform4iv(getUniformLocation(name), count, ptr);
    }

    /*
     * GLuint uniform array specialization
     */

    template <>
    inline void ShaderProgram::setUniformPtr<1, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform1uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<2, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform2uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<3, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform3uiv(getUniformLocation(name), count, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformPtr<4, GLuint>(const std::string& name, const GLuint* ptr, GLsizei count)
    {
        glUniform4uiv(getUniformLocation(name), count, ptr);
    }

    /*
     * GLfloat matrix uniform array specialization
     */

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<2, 2, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix2fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<3, 3, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix3fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<4, 4, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix4fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<2, 3, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix2x3fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<3, 2, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix3x2fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<2, 4, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix2x4fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<4, 2, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix4x2fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<3, 4, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix3x4fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<4, 3, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix4x3fv(getUniformLocation(name), count, transpose, ptr);
    }

    /*
     * GLfloat square matrix uniform array specialization
     */

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<2, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix2fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<3, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix3fv(getUniformLocation(name), count, transpose, ptr);
    }

    template <>
    inline void ShaderProgram::setUniformMatrixPtr<4, GLfloat>(const std::string& name, const GLfloat* ptr, GLboolean transpose, GLsizei count)
    {
        glUniformMatrix4fv(getUniformLocation(name), count, transpose, ptr);
    }

    inline void ShaderProgram::setUniformSubroutine(ShaderObject::ShaderType type, const std::string& uniform, const std::string& subroutine)
    {
        if (!_subroutines.count(type))
            throw(mogl::ShaderException("no subroutine for this shader stage"));
        SubroutineMap& routineMap = _subroutines.at(type);

        if (!routineMap.count(uniform))
            throw(mogl::ShaderException("invalid uniform name"));
        SubroutineUniform& subUniform = routineMap.at(uniform);

        if (!subUniform.subroutines.count(subroutine))
            throw(mogl::ShaderException("invalid subroutine"));

        GLuint  uniformIdx = subUniform.uniform;
        GLuint  subroutineIdx = subUniform.subroutines.at(subroutine);
        GLsizei size = routineMap.size();
        GLuint  indices[size];

        indices[uniformIdx] = subroutineIdx;
        glUniformSubroutinesuiv(static_cast<GLenum>(type), size, indices);
    }
}

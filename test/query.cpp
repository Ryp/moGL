////////////////////////////////////////////////////////////////////////////////
/// Modern OpenGL Wrapper
///
/// Copyright (c) 2015 Thibault Schueller
/// This file is distributed under the MIT License
///
/// @file query.cpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" // For IDE completion only

class QueryObjectTest : public GLTestFixture {};

using mogl::QueryObject;

TEST_F(QueryObjectTest, timer)
{
    QueryObject qo(GL_TIME_ELAPSED);

    qo.begin();
    qo.end();
    GLint rslt1 = qo.getResult<GLint>(GL_QUERY_RESULT);
    GLuint rslt2 = qo.getResult<GLuint>(GL_QUERY_RESULT);
    GLint64 rslt3 = qo.getResult<GLint64>(GL_QUERY_RESULT);
    GLuint64 rslt4 = qo.getResult<GLuint64>(GL_QUERY_RESULT);

    static_cast<void>(rslt1);
    static_cast<void>(rslt2);
    static_cast<void>(rslt3);
    static_cast<void>(rslt4);

    EXPECT_TRUE(qo.isValid());
}

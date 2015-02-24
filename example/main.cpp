#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

using namespace gl;

#include "common/glcontext.hpp"

#include <fstream>

#include <mogl/shader.hpp>
#include <mogl/texture.hpp>
#include <mogl/buffer/bufferobject.hpp>
#include <mogl/buffer/vertexarrayobject.hpp>
#include <mogl/queryobject.hpp>
#include <mogl/states/states.hpp>

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "ImageLoader.hpp"
#include "Model.hh"
#include "ModelLoader.hh"

void    example(GLContext& ctx)
{
    ModelLoader             loader;
    Model*                  mesh = loader.load("data/cube.obj");
    mogl::VertexArrayObject vao;
    mogl::BufferObject      vertexBuffer(GL_ARRAY_BUFFER);
    mogl::BufferObject      normalBuffer(GL_ARRAY_BUFFER);
    mogl::BufferObject      uvBuffer(GL_ARRAY_BUFFER);
    mogl::BufferObject      elementBuffer(GL_ELEMENT_ARRAY_BUFFER);
    mogl::TextureObject     texture(GL_TEXTURE_2D);
    mogl::QueryObject       timeQuery(GL_TIME_ELAPSED);
    mogl::QueryObject       polyQuery(GL_PRIMITIVES_GENERATED);
    std::ifstream           vsFile("data/basic_shading.vert");
    std::ifstream           fsFile("data/basic_shading.frag");
    mogl::ShaderProgram     shader;
    mogl::ShaderObject      vertex(vsFile, mogl::ShaderObject::ShaderType::VertexShader);
    mogl::ShaderObject      fragment(fsFile, mogl::ShaderObject::ShaderType::FragmentShader);
    glm::mat4               Projection  = glm::perspective(45.0f, static_cast<float>(ctx.getWindowSize().x) / static_cast<float>(ctx.getWindowSize().y), 0.1f, 100.0f);
    glm::mat4               View        = glm::lookAt(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(), glm::vec3(0, 1, 0));
    glm::mat4               Model       = glm::mat4(1.0);
    glm::mat4               MV          = View * Model;
    glm::mat4               MVP         = Projection * MV;
    glm::vec3               lightInvDir = glm::vec3(0.5f, 2, 2);

    texture.bind(0);
    ImageLoader::loadDDS("data/uvmap.dds", texture);

    if (!vertex.compile())
        throw (std::runtime_error("Vertex shader failed to compile\n" + vertex.getLog()));
    if (!fragment.compile())
        throw (std::runtime_error("Fragment shader failed to compile\n" + fragment.getLog()));
    shader.attach(vertex);
    shader.attach(fragment);
    if (!shader.link())
        throw (std::runtime_error("Program failed to link\n" + shader.getLog()));

    vertexBuffer.setData(mesh->getVertexBufferSize(), mesh->getVertexBuffer(), GL_STATIC_DRAW);
    normalBuffer.setData(mesh->getNormalBufferSize(), mesh->getNormalBuffer(), GL_STATIC_DRAW);
    uvBuffer.setData(mesh->getUVBufferSize(), mesh->getUVBuffer(), GL_STATIC_DRAW);
    elementBuffer.setData(mesh->getIndexBufferSize(), mesh->getIndexBuffer(), GL_STATIC_DRAW);

    vao.bind();
//     vao.enableAttrib(0);
//     vao.enableAttrib(1);
//     vao.enableAttrib(2);
//     vao.setAttribBinding(0, 0);
//     vao.setAttribBinding(1, 1);
//     vao.setAttribBinding(2, 2);
//     vao.setAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 12);
//     vao.setAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 12);
//     vao.setAttribFormat(2, 2, GL_FLOAT, GL_FALSE, 8);
//     vao.setVertexBuffer(0, vertexBuffer.getHandle(), 0, 0);
//     vao.setVertexBuffer(1, normalBuffer.getHandle(), 0, 0);
//     vao.setVertexBuffer(2, uvBuffer.getHandle(), 0, 0);
//     vao.setElementBuffer(elementBuffer.getHandle());

    mogl::enable(GL_DEPTH_TEST);
    mogl::enable(GL_CULL_FACE);
    mogl::setCullFace(GL_BACK);
    glDepthFunc(GL_LESS);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glViewport(0, 0, ctx.getWindowSize().x, ctx.getWindowSize().y);
    while (ctx.isOpen())
    {
        float frameTime = ctx.getTime();
        timeQuery.begin();
        polyQuery.begin();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        texture.bind(0);
        shader.setUniform<GLint>("uvTex", 0);
        shader.setUniformMatrixPtr<4>("MVP", &MVP[0][0]);
        shader.setUniformMatrixPtr<4>("MV", &MV[0][0]);
        shader.setUniformMatrixPtr<4>("V", &View[0][0]);
        shader.setUniformPtr<3>("lightInvDirection_worldspace", &lightInvDir[0]);

        vao.bind();
        vao.enableAttrib(0);
        vao.enableAttrib(1);
        vao.enableAttrib(2);

        vertexBuffer.bind();
        shader.setVertexAttribPointer(0, 3, GL_FLOAT);
        normalBuffer.bind();
        shader.setVertexAttribPointer(1, 3, GL_FLOAT);
        uvBuffer.bind();
        shader.setVertexAttribPointer(2, 2, GL_FLOAT);

        elementBuffer.bind();
        glDrawElements(GL_TRIANGLES, mesh->getIndexBufferSize(), GL_UNSIGNED_INT, nullptr);

        vao.disableAttrib(0);
        vao.disableAttrib(1);
        vao.disableAttrib(2);

        polyQuery.end();
        timeQuery.end();
        double glms = static_cast<double>(timeQuery.getResult<GLuint>(GL_QUERY_RESULT)) * 0.000001;
        unsigned int poly = polyQuery.getResult<GLuint>(GL_QUERY_RESULT);

        ctx.swapBuffers();
        frameTime = ctx.getTime() - frameTime;
        ctx.setTitle(std::to_string(poly) + " Primitives | Total " + std::to_string(frameTime * 1000.0f) + " ms / GPU " + std::to_string(glms) + " ms " + std::to_string(ctx.getWindowSize().x) + "x"  + std::to_string(ctx.getWindowSize().y));
    }
}

int main(int /*ac*/, char** /*av*/)
{
    auto debugCallback = [] (GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *message, const void *) { std::cout << "GL: " << message << std::endl; };
    try {
        GLContext   ctx;

        ctx.create(800, 600, 4, 5, false, true);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(debugCallback, nullptr);
        GLuint unusedIds = 0;
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, &unusedIds, GL_TRUE);
        example(ctx);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

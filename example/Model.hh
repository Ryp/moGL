#ifndef MODEL_HH
#define MODEL_HH

#include <vector>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Model
{
    friend class ModelLoader;
public:
    Model();
    ~Model();

public:
    void        debugDump();
    std::size_t getTriangleCount() const;
    void        computeTangents();
    void        computeNormalsSimple();

public:
    const void* getVertexBuffer() const;
    std::size_t getVertexBufferSize() const;
    const void* getUVBuffer() const;
    std::size_t getUVBufferSize() const;
    const void* getNormalBuffer() const;
    std::size_t getNormalBufferSize() const;
    const void* getIndexBuffer() const;
    std::size_t getIndexBufferSize() const;
    const void* getTangentBuffer() const;
    std::size_t getTangentBufferSize() const;
    const void* getBitangentBuffer() const;
    std::size_t getBitangentBufferSize() const;

private:
    bool    _isIndexed;
    bool    _hasUVs;
    bool    _hasNormals;

private:
    std::vector<glm::vec3>    _vertices;
    std::vector<glm::vec3>    _normals;
    std::vector<glm::vec2>    _uvs;
    std::vector<unsigned int> _indexes;

    std::vector<glm::vec3>    _tangents;
    std::vector<glm::vec3>    _bitangents;
};

#endif // MODEL_HH

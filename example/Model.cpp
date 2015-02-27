#include "Model.hh"

/* FIXME */
#include <iostream>
#include <glm/geometric.hpp>

Model::Model()
:   _isIndexed(false),
    _hasUVs(false),
    _hasNormals(false)
{}

Model::~Model() {}

/* FIXME Rm me */
void Model::debugDump()
{
    std::cout << "Total triangles: " << getTriangleCount() << std::endl;
    std::cout << "Total vertices: " << _vertices.size() << std::endl;
    std::cout << "Total normals: " << _normals.size() << std::endl;
    std::cout << "Total uvs: " << _uvs.size() << std::endl;
    std::cout << "Total indexes: " << _indexes.size() << std::endl;
    //   for (unsigned i = 0; i < _vertices.size(); ++i)
    //     std::cout << "Vertex: " << _vertices[i][0] << " " << _vertices[i][1] << " " << _vertices[i][2] << std::endl;
    //   for (unsigned i = 0; i < _normals.size(); ++i)
    //     std::cout << "Normal: " << _normals[i][0] << " " << _normals[i][1] << " " << _normals[i][2] << std::endl;
    //   for (unsigned i = 0; i < _uvs.size(); ++i)
    //     std::cout << "UV: " << _uvs[i][0] << " " << _uvs[i][1] << std::endl;
    //   for (unsigned i = 0; i < _indexes.size(); ++i)
    //     std::cout << "Index: " << _indexes[i] << std::endl;
}

std::size_t Model::getTriangleCount() const
{
    if (_isIndexed)
        return _indexes.size();
    else
        return _vertices.size() / 3;
}

void Model::computeTangents()
{
    if (_hasNormals && _hasUVs)
    {
        /* TODO Compute tangents */
    }
}

void Model::computeNormalsSimple()
{
    std::size_t trianglesNo = getTriangleCount();

    _normals.resize(_vertices.size());
    for (std::size_t i = 0; i < trianglesNo; ++i)
    {
        glm::vec3   a = _vertices[i * 3 + 1] - _vertices[i * 3 + 0];
        glm::vec3   b = _vertices[i * 3 + 2] - _vertices[i * 3 + 0];
        glm::vec3   n = glm::normalize(glm::cross(a, b));

        _normals[i * 3 + 0] = n;
        _normals[i * 3 + 1] = n;
        _normals[i * 3 + 2] = n;
    }
}

const void* Model::getVertexBuffer() const
{
    return &_vertices[0];
}

std::size_t Model::getVertexBufferSize() const
{
    return _vertices.size() * sizeof(_vertices[0]);
}

const void* Model::getUVBuffer() const
{
    return &_uvs[0];
}

std::size_t Model::getUVBufferSize() const
{
    return _uvs.size() * sizeof(_uvs[0]);
}

const void* Model::getNormalBuffer() const
{
    return &_normals[0];
}

std::size_t Model::getNormalBufferSize() const
{
    return _normals.size() * sizeof(_normals[0]);
}

const void* Model::getIndexBuffer() const
{
    return &_indexes[0];
}

std::size_t Model::getIndexBufferSize() const
{
    return _indexes.size() * sizeof(_indexes[0]);
}

const void* Model::getTangentBuffer() const
{
    return &_tangents[0];
}

std::size_t Model::getTangentBufferSize() const
{
    return _tangents.size() * sizeof(_tangents[0]);
}

const void* Model::getBitangentBuffer() const
{
    return &_bitangents[0];
}

std::size_t Model::getBitangentBufferSize() const
{
    return _bitangents.size() * sizeof(_bitangents[0]);
}

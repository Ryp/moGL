#ifndef MODELLOADER_HH
#define MODELLOADER_HH

#include <fstream>
#include <string>
#include <map>

#include "Model.hh"

class ModelLoader
{
public:
    ModelLoader();
    ~ModelLoader();

public:
    Model*    load(std::string filename);

private:
    Model*    loadOBJ(std::ifstream& src);

private:
    std::map<std::string, Model* (ModelLoader::*)(std::ifstream&)> _parsers;
};

#endif // MODELLOADER_HH

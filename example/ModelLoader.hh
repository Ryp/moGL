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
    using MLF = Model* (ModelLoader::*)(std::ifstream&);
    std::map<std::string, MLF> _parsers;
};

#endif // MODELLOADER_HH

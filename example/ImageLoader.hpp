////////////////////////////////////////////////////////////////////////////////
/// ReaperGL
///
/// Copyright (c) 2015 Thibault Schueller
///
/// @file imageloader.hpp
/// @author Thibault Schueller <ryp.sqrt@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef IMAGELOADER_INCLUDED
#define IMAGELOADER_INCLUDED

#include <string>

namespace mogl { class Texture; }

class ImageLoader
{
    ImageLoader() = delete;

public:
    static void loadDDS(const std::string& file, mogl::Texture& texture);
};

#endif // IMAGELOADER_INCLUDED

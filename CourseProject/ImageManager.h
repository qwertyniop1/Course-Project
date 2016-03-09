/*#pragma once

#include "Texture.h"

#include <map>

class ImageManager
{
public:
    ImageManager(SDL_Renderer *renderer);
    bool addTexture(FILE_PATH path, int id);
    Texture* getTexture(int id);

private:
    std::map<int, Texture*> textures;
    SDL_Renderer *textureRenderer;

};*/
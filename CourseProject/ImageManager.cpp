/*#include "ImageManager.h"

ImageManager::ImageManager(SDL_Renderer * renderer)
{
    textureRenderer = renderer;
}

bool ImageManager::addTexture(FILE_PATH path, int id)
{
    Texture newTexture;
    if (!newTexture.loadTexture(textureRenderer, path)) {
        return false;
    }

    textures.insert(std::pair<int, Texture*>(id, &newTexture));
   
}

Texture * ImageManager::getTexture(int id)
{
    if (textures.find(id) == textures.end()) {
        return nullptr;
    }
    return textures[id];
}

*/
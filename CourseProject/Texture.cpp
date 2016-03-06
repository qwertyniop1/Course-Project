#include "Texture.h"

Texture::Texture()
{
    height = 0;
    width = 0;
    texture = nullptr;
}

Texture::~Texture()
{
    free();
}

bool Texture::loadTexture(SDL_Renderer *renderer, FILE_PATH path)
{
    free();

    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = nullptr;

    loadedSurface = IMG_Load(path);
    if (loadedSurface == nullptr) {
        return false;
    }
  
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        return false;
    }

    width = loadedSurface->w;
    height = loadedSurface->h;
    texture = newTexture;

    SDL_FreeSurface(loadedSurface);

    return true;
}

bool Texture::loadTexture(SDL_Renderer *renderer, FILE_PATH path, SDL_Color *colorKey)
{
    free();

    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = nullptr;

    loadedSurface = IMG_Load(path);
    if (loadedSurface == nullptr) {
        return false;
    }

    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, colorKey->r, colorKey->g, colorKey->b));
    
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        return false;
    }

    width = loadedSurface->w;
    height = loadedSurface->h;
    texture = newTexture;

    SDL_FreeSurface(loadedSurface);

    return true;
}

void Texture::free()
{
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void Texture::render(SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect textureRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &textureRect);
}

int Texture::getHeight()
{
    return height;
}

int Texture::getWidth()
{
    return width;
}


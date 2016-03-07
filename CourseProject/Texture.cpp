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

int Texture::getHeight()
{
    return height;
}

int Texture::getWidth()
{
    return width;
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

void Texture::setColor(byte red, byte green, byte blue)
{
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(byte alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(SDL_Renderer * renderer, int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
    SDL_Rect textureRect = { x, y, width, height };

    if (clip != NULL) {
        textureRect.h = clip->h;
        textureRect.w = clip->w;
    }

    SDL_RenderCopyEx(renderer, texture, clip, &textureRect, angle, center, flip);
}

/*
void Texture::render(SDL_Renderer * renderer, int x, int y, SDL_Rect * clip)
{
SDL_Rect textureRect = { x, y, width, height };

if (clip != NULL) {
textureRect.h = clip->h;
textureRect.w = clip->w;
}

SDL_RenderCopy(renderer, texture, clip, &textureRect);
}
*/



#pragma once
#include "Graphic.h"

class Texture
{
public:
    Texture();
    ~Texture();

    bool loadTexture(SDL_Renderer *renderer, FILE_PATH path);
    bool loadTexture(SDL_Renderer *renderer, FILE_PATH path, SDL_Color *colorKey);
              
    void free();
    void render(SDL_Renderer *renderer, int x, int y);

    int getHeight();
    int getWidth();

private:
    SDL_Texture *texture;
    int width;
    int height;

};


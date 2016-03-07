#pragma once
#include "Graphic.h"

class Texture
{
public:
    Texture();
    ~Texture();

    bool loadTexture(SDL_Renderer *renderer, FILE_PATH path);
    bool loadTexture(SDL_Renderer *renderer, FILE_PATH path, SDL_Color *colorKey);

    void setColor(byte red, byte green, byte blue);

    void setBlendMode(SDL_BlendMode blending);

    void setAlpha(byte alpha);
              
    void free();
    //void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = NULL);
    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    int getHeight();
    int getWidth();

private:
    SDL_Texture *texture;
    int width;
    int height;

};


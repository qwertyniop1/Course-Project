#pragma once

#include "Animation.h"
#include "Texture.h"

class Entity
{
protected:
    Animation animControl;
    Texture *sprite = nullptr;

    int x;
    int y;
    int weigth;
    int height;

    SDL_Rect textureRect;

public:
    virtual bool load(FILE_PATH path, SDL_Renderer *renderer);
    virtual void move();
    virtual void animate();
    virtual void render(SDL_Renderer *renderer);
    virtual void cleanup();

    void setTextureRect(int x, int y, int height, int weigth);

};

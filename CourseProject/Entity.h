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
    int width;
    int height;

    SDL_Rect textureRect;

    int animState;

public:
    virtual bool load(FILE_PATH path, SDL_Renderer *renderer);
    virtual void move(int dx, int dy); //tmp
    virtual void animate();
    virtual void render(SDL_Renderer *renderer);
    virtual void cleanup();

    void setTextureRect(int x, int y, int width, int height);
    void setPosition(int x, int y);

    void setMaxFrame(int frames); //???
    void setAnimState(int state);
        
};

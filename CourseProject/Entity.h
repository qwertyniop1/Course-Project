#pragma once

#include "Animation.h"
#include "Texture.h"

enum Direction
{
    LEFT,
    RIGTH
};

class Entity
{
protected:
    Animation animControl;
    Texture *sprite = nullptr;

    int x;
    int y;
    int width;
    int height;

    int dx;
    int dy;

    SDL_Rect textureRect;
    int startX, startY;

    byte animState;
    Direction orientation; //


public:
    virtual bool load(FILE_PATH path, SDL_Renderer *renderer, SDL_Color *colorKey = NULL);
    virtual void move();
    virtual void move(int dx, int dy); //tmp
    virtual void animate();
    virtual void render(SDL_Renderer *renderer);
    virtual void cleanup();

   //void checkCollision();

    void setTextureRect(int x, int y, int width, int height);
    void setPosition(int x, int y);

    void setMaxFrame(int frames); //???
    void setAnimState(int state);
    void setOrientation(Direction dir); //////
        
};


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

    bool onGround;

    SDL_Rect textureRect;
    int startX, startY;

    byte animState;
    Direction orientation; //


public:
    virtual bool load(FILE_PATH path, SDL_Renderer *renderer, SDL_Color *colorKey = NULL);
    virtual void move();
    virtual void move(int dx, int dy); //tmp
    virtual void animate();
    virtual void render(SDL_Renderer *renderer, int offsetX, int offsetY);
    virtual void cleanup();

    SDL_Rect getRect();
    int getDX();
    int getDY();
    void setDX(int value);
    void setDY(int value);
    //void setDX(int value);
   

    void setTextureRect(int x, int y, int width, int height);
    void setPosition(int x, int y);

    void setMaxFrame(int frames); //???
    void setAnimState(int state);
    void setOrientation(Direction dir); //////

    void setOnGround(bool flag);

    virtual void moveX();
    virtual void moveY();
        
};


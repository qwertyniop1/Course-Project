#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
    bool onGround;

public:
    Player();

    void move();
    void move(int dx, int dy);

    bool isOnSurface();
    void setOnGround(bool flag);
};
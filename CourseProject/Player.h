#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
    

public:
    Player();

    void move();
    void move(int dx, int dy);

    //
    void moveX();
    void moveY();
    //

    bool isOnSurface();
    
};
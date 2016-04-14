#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
    

public:
    Player();

    void move();
    void move(int dx);

    //
    void moveX();
    void moveY();
    //

    bool isOnSurface();
    
};
#include "Enemy.h"

Enemy::Enemy()
{
    //return ignored

    dx = 0;
    dy = 0;

      //
    
    setMaxFrame(1);
    setAnimState(0);
}

void Enemy::moveX()
{
    //
    
    //
    x += this->dx;
}

void Enemy::moveY()
{
    if (!onGround) {
        this->dy += 1;
    }
    y += this->dy;

    if (dx != 0) onGround = false;
}

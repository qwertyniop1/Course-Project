#include "Player.h"

Player::Player()
{
    dx = 0;
    dy = 0;
}

void Player::move()
{

}

void Player::moveX()
{
    x += this->dx;
}

void Player::moveY()
{
    if (!onGround) {
        this->dy += 1;
    }
    y += this->dy;

    if (dx != 0) onGround = false;    
}

void Player::move(int dx)
{
    
    this->dx = dx;
           
    if (dx > 0) {
        orientation = RIGTH;
    }
    else if (dx < 0) {
        orientation = LEFT;
    }

}

bool Player::isOnSurface()
{
    return onGround;
}


#include "Player.h"

Player::Player()
{
    onGround = true;
    dx = 0;
    dy = 0;
}

void Player::move()
{
    x += this->dx;

    y += this->dy;

    //onGround = false;

    if (!onGround) {
        this->dy += 1;
    }

    if (y > WINDOW_HEIGTH - 80) {
        y = WINDOW_HEIGTH - 80;
        this->dy = 0;
        onGround = true;
    }
}

void Player::move(int dx, int dy)
{
    this->dx = dx;
    this->dy += dy;
       
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

void Player::setOnGround(bool flag)
{
    onGround = flag;
}

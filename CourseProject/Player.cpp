#include "Player.h"

Player::Player()
{
    dx = 0;
    dy = 0;
}

void Player::move()
{/*
    x += this->dx;
   
    y += this->dy;
   
    if (!onGround) {
        this->dy += 1;
    }

    if (y > WINDOW_HEIGTH - 80) { //
        y = WINDOW_HEIGTH - 80; //
        this->dy = 0;
        onGround = true;
    }*/
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

   /*if (y > WINDOW_HEIGTH - 80) { //
        y = WINDOW_HEIGTH - 80; //
        this->dy = 0;
        onGround = true;
    }*/
    //dx = 0;
    
}

void Player::move(int dx, int dy)
{
    //if (dx != 0)
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


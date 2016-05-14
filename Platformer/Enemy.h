#pragma once
#include "Global.h"
class Enemy {
public:
    double dx, dy;
    sf::FloatRect rect;
    bool onSurface;
    sf::Sprite sprite;
    double currentFrame;
    //
    bool isAlive;

    Enemy(sf::Texture &image, int x, int y);

    void update(double time);
    void collision(Direction dir);
};

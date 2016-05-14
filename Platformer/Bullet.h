#pragma once

#include "AnimationManager.h"

class Bullet {
public:
    double dx, dy;
    double x, y, width, height;
    AnimationManager animationManager;
    bool isAlive;

    Bullet(AnimationManager &manager, int x, int y, Direction dir);

    void update(double time);

    void draw(sf::RenderWindow &window);
};

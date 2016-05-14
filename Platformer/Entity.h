#pragma once
#include "AnimationManager.h"

class Entity {
public:
    double dx, dy;
    double x, y, width, height;
    AnimationManager animationManager;
    Direction dir;
    bool isAlive;

    Entity(AnimationManager &manager, int x, int y);

    virtual void update(double time) = 0;

    void draw(sf::RenderWindow &window);
};

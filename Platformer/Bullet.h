#pragma once

#include "AnimationManager.h"
#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(AnimationManager &manager, int x, int y, Direction dir);

    void update(double time);

    void draw(sf::RenderWindow &window);
};

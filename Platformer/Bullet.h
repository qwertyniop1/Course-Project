#pragma once

#include "AnimationManager.h"
#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(AnimationManager &manager, int x, int y, Direction dir, Level &level);

    void update(double time);

    void collision();
};

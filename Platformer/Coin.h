#pragma once

#include "AnimationManager.h"
#include "Entity.h"

class Coin : public Entity {
public:
    Coin(AnimationManager &manager, int x, int y, Level &level);

    void update(double time);

};

#pragma once

#include "Global.h"
#include "AnimationManager.h"
#include "Entity.h"

class Enemy : public Entity {
public:   

    Enemy(AnimationManager &manager, int x, int y, Level &level);

    void update(double time);
    void collision(CollisionDirection dir);
};

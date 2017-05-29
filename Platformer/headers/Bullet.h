#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(AnimationManager &manager, int x, int y, Direction dir, Level &level);

    void update(double time);

    void collision();

private:
    const double BULLET_SPEED = 0.3;
    const int BULLET_SIZE = 5;
};

#endif

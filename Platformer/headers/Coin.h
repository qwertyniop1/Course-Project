#ifndef COIN_H
#define COIN_H

#include "Entity.h"

class Coin : public Entity {
public:
    Coin(AnimationManager &manager, int x, int y, Level &level);

    void update(double time);

private:
    const int COIN_SIZE = 32;
};

#endif

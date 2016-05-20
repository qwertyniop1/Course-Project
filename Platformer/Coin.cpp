#include "Coin.h"

Coin::Coin(AnimationManager & manager, int x, int y, Level & level) : Entity(manager, x, y, level)
{
    name = "Coin";
    animationManager.set("coin");
    
    alive = true;

    width = height = 32;
}

void Coin::update(double time)
{
    animationManager.tick(time);
}

#include "Bullet.h"

Bullet::Bullet(AnimationManager &manager, int x, int y, Direction dir) : Entity(manager, x, y)
{
    name = "Bullet";   
    animationManager.set("move");   

    if (dir == Direction::Flip) {
        dx = -0.3;
    }
    else {
        dx = 0.3;
    }

    isAlive = true;

    width = height = 18;

}

void Bullet::update(double time)
{
    x += dx * time;

    //collision

    animationManager.tick(time);
}


#include "Bullet.h"

Bullet::Bullet(AnimationManager &manager, int x, int y, Direction dir, Level &level) : Entity(manager, x, y, level)
{
    name = "Bullet";   
    animationManager.set("shoot");   

    if (dir == Direction::Flip) {
        dx = -0.3;
    }
    else {
        dx = 0.3;
    }

    alive = true;

    width = height = 5;

}

void Bullet::update(double time)
{
    x += dx * time;

    collision();

    animationManager.tick(time);
}

void Bullet::collision()
{
    std::vector<Object> objects = level.getObjects("solid");
    for (size_t i = 0; i < objects.size(); ++i) {
        if (getRect().intersects(objects[i].rect)) {
            alive = false;
        }
    }
}




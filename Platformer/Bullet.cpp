#include "Bullet.h"

Bullet::Bullet(AnimationManager &manager, int x, int y, Direction dir) : Entity(manager, x, y)
{
    name = "Bullet";
    animationManager = manager;
    animationManager.set("move");
    this->x = x;
    this->y = y;    

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

    for (size_t i = y / 32; i < (y + height) / 32; ++i) {
        for (size_t j = x / 32; j < (x + width) / 32; ++j) {
            if (tileMap[i][j] == 'B') {
                animationManager.set("explode");
                dx = 0;
                isAlive = false;
            }
        }

    }

    animationManager.tick(time);
}

void Bullet::draw(sf::RenderWindow & window)
{
    animationManager.draw(window, x - offsetX, y - offsetY); //offset
}

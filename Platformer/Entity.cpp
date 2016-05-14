#include "Entity.h"

Entity::Entity(AnimationManager & manager, int x, int y)
{
    animationManager = manager;
    this->x = x;
    this->y = y;
    dir = Direction::Normal;
    isAlive = true;
    dx = dy = 0;
}

void Entity::draw(sf::RenderWindow & window)
{
    animationManager.draw(window, x - offsetX, y - offsetY);
}

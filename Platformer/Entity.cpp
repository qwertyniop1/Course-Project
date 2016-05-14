#include "Entity.h"

Entity::Entity(AnimationManager & manager, int x, int y)
{
    animationManager = manager;
    this->x = x;
    this->y = y;
    width = animationManager.getWidth();
    height = animationManager.getHeight();
    dir = Direction::Normal;
    isAlive = true;
    dx = dy = 0;
}

void Entity::draw(sf::RenderWindow & window)
{
    animationManager.draw(window, x, y);
}

sf::FloatRect Entity::getRect()
{
    return sf::FloatRect(x, y, width, height);
}

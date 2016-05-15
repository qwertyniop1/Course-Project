#include "Entity.h"

Entity::Entity(AnimationManager & manager, int x, int y, Level &level)
{
    animationManager = manager;
    ///manager.set("stay"); // delete
    this->x = x;
    this->y = y;
    width = /*animationManager.getWidth();*/40;
    height = animationManager.getHeight();
    direction = Direction::Normal;
    isAlive = true;
    dx = dy = 0;
    this->level = level;

}

void Entity::draw(sf::RenderWindow & window)
{
    animationManager.draw(window, x, y);
}

sf::FloatRect Entity::getRect()
{
    return sf::FloatRect(x, y, width, height);
}

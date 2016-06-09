#include "Entity.h"

Entity::Entity(AnimationManager & manager, int x, int y, Level &level)
{
    animationManager = manager;
    this->x = x;
    this->y = y;
    width = /*animationManager.getWidth();*/40;
    height = animationManager.getHeight();
    direction = Direction::Normal;
    alive = true;
    dx = dy = 0;
    this->level = level;
    health = 0;
    timer = 0;
}

void Entity::draw(sf::RenderWindow & window)
{
    animationManager.draw(window, x, y + height);
}

sf::FloatRect Entity::getRect()
{
    return sf::FloatRect(x, y, width, height);
}

bool Entity::isAlive()
{
    return alive;
}

void Entity::eliminate()
{
    alive = false;
}

std::string Entity::getName()
{
    return name;
}

Direction Entity::getDirection()
{
    return direction;
}

void Entity::changeHealth(int value)
{
    health += value;
}

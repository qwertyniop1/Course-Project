#pragma once
#include "AnimationManager.h"
#include "Level.h"

class Entity {
public:
    double dx, dy;
    double x, y, width, height;
    AnimationManager animationManager;
    Direction direction;
    bool isAlive;
    std::string name;

    Level level;

    Entity(AnimationManager &manager, int x, int y, Level &level);

    virtual void update(double time) = 0;

    void draw(sf::RenderWindow &window);

    sf::FloatRect getRect();

};

#pragma once
#include "AnimationManager.h"
#include "Level.h"

class Entity {
public:
    Level level;

    Entity(AnimationManager &manager, int x, int y, Level &level);

    virtual void update(double time) = 0;

    void draw(sf::RenderWindow &window);

    sf::FloatRect getRect();

    bool isAlive();

    void eliminate();

    std::string getName();

    Direction getDirection();

    void changeHealth(int value);

protected:

    double x, y, width, height;
    AnimationManager animationManager;
    Direction direction;
    std::string name;
    bool alive;

    int health;
    double timer;

public:
    double dx, dy; /* tmp */
};

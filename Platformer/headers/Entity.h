#ifndef ENTITY_H
#define ENTITY_H 

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
    const double ACCELERATION = 0.0005;

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


#endif

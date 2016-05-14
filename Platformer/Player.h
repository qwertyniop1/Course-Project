#pragma once
#include "Global.h"
#include "AnimationManager.h"

class Player {
public:
    double dx, dy;
    sf::FloatRect rect;
    AnimationManager animationManager;
    bool isShooting, isOnLadder, isHit;
    //bool onSurface;   

    enum Key {
        Left, Right, Up, Down, Space
    };

    enum Direction {
        Normal, Flip
    };

    Direction direction;

    std::map<Key, bool> keys;
       
    enum State {
        Stay, Walk, Duck, Jump, Climb, Swim
    };

    State currentState;

    Player(AnimationManager &manager);

    void handleKeys();

    void update(double time);
    void collision(CollisionDirection dir);
    void draw(sf::RenderWindow &window);

};
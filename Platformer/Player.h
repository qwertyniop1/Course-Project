#pragma once
#include "Global.h"
#include "Entity.h"
#include "AnimationManager.h"
#include "Level.h"

class Player : public Entity{
public:
    bool isShooting, isOnLadder, isHit;
    Level level;

    enum Key {
        Left, Right, Up, Down, Space
    };   

    Direction direction;

    std::map<Key, bool> keys;
       
    enum State {
        Stay, Walk, Duck, Jump, Climb, Swim
    };

    State currentState;

    Player(AnimationManager &manager, int x, int y, Level &level);

    void handleKeys();

    void update(double time);
    void collision(CollisionDirection dir);
};
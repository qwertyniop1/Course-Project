#pragma once
#include "Global.h"
#include "AnimationManager.h"
#include "Entity.h"

class Player : public Entity{
public:    
    Player(AnimationManager &manager, int x, int y, Level &level);

    void handleKeys();

    void update(double time);

    void collision(CollisionDirection dir);

    enum Key {
        Left, Right, Up, Down, Space
    };

    enum State {
        Stay, Walk, Duck, Jump, Climb, Swim
    };

private:
    bool isShooting, isOnLadder, isHit;   
    State currentState;

public:
    std::map<Key, bool> keys;

};
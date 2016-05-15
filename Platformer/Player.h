#pragma once
#include "Global.h"
#include "AnimationManager.h"
#include "Entity.h"

class Player : public Entity{
public:    
    bool isShooting, isOnLadder, isHit;    

    enum Key {
        Left, Right, Up, Down, Space
    };   

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
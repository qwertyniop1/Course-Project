#ifndef PLAYER_H
#define PLAYER_H 

#include "Global.h"
#include "AnimationManager.h"
#include "Entity.h"

enum PlayerSounds {
    NONE, JUMP_S, HIT_S
};

class Player : public Entity{
public:    
    Player(AnimationManager &manager, int x, int y, Level &level);

    void handleKeys();

    void update(double time);

    void collision(CollisionDirection dir);

    void setHit(bool flag);

    bool isHit();

    int getHealth();

    void setSound(PlayerSounds flag);

    PlayerSounds getSound();

    enum Key {
        Left, Right, Up, Down, Space
    };

    enum State {
        Stay, Walk, Duck, Jump, Climb, Swim
    };

private:
    const int HEALTH = 30;
    const double PLAYER_SPEED = 0.15; 
    const double LADDER_GRAVITY = 0.05;
    const double GRAVITY = 0.35; //0.27

    bool isShooting, isOnLadder, hit;   
    State currentState;

    PlayerSounds sound;

public:
    std::map<Key, bool> keys;

};

#endif

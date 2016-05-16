#pragma once
#include <iostream>

#include "Global.h"
#include "AnimationManager.h"
#include "Entity.h"
#include <list>

#include "Enemy.h"
#include "Player.h"

class Application
{
public:
    Application() {};

    int onExecute();

    bool onInit();

    void onCleanup();

private:
    sf::RenderWindow window;
    sf::View view;

    AnimationManager animationManager;

    sf::Texture playerTexture;
    sf::Texture bulletTexture;

    Level level;
    std::list<Entity*> entities;

    std::vector<Object> enemies;
    Player *player;

};


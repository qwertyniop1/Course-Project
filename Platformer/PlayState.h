#pragma once

#include <iostream>
#include <list>

#include "GameState.h"
#include "AnimationManager.h"
#include "Entity.h"

#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Coin.h"

#include "MenuState.h"
#include "GameOverState.h"

class PlayState : public GameState
{
protected:
    PlayState(GameStateManager *manager) { stateManager = manager; };

public:
    static PlayState* getInstance(GameStateManager *manager)
    {
        static PlayState self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(sf::Event event);
    void onLoop();
    void onRender(sf::RenderWindow &window);
    void onCleanup();

private:
    sf::View view;
    sf::Clock clock;
    
    AnimationManager playerAnimation;
    AnimationManager bulletAnimation;
    AnimationManager coinAnimation;

    sf::Texture playerTexture;
    sf::Texture bulletTexture;
    sf::Texture coinTexture;

    Level *level;
    std::list<Entity*> entities;

    std::vector<Object> enemies;
    Player *player;

    sf::Font font;
    sf::Text scoreText;
    size_t score;
    sf::Texture lifeScoreTexture;
    sf::Sprite lifeScore;
};


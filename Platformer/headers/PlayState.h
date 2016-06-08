#ifndef PLAY_STATE_H
#define PLAY_STATE_H 

#include <list>

#include "GameState.h"
#include "AnimationManager.h"
#include "Enemy.h"
#include "Player.h"
#include "Coin.h"

const size_t LEVELS_QUANTITY = 4;

class PlayState : public GameState
{
protected:
    PlayState(GameStateManager *manager) { 
        stateManager = manager;
        levels.assign(levelsPath, levelsPath + LEVELS_QUANTITY);
        score = 0;
    };

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
    sf::Clock clock, timer;
    
    AnimationManager playerAnimation;
    AnimationManager enemyAnimation;
    AnimationManager bulletAnimation;
    AnimationManager coinAnimation;

    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Texture bulletTexture;
    sf::Texture coinTexture;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    Level *level;
    std::list<Entity*> entities;

    std::vector<Object> enemies;
    Player *player;

    sf::Font font;
    sf::Text scoreText;
    size_t score;
    sf::Texture lifeScoreTexture;
    sf::Sprite lifeScore;

    const std::string levelsPath[LEVELS_QUANTITY] = {"res/level1.tmx", "res/level2.tmx", "res/level3.tmx", "res/level4.tmx" };
    std::vector<std::string> levels;
    bool loadLevel();


};




#endif



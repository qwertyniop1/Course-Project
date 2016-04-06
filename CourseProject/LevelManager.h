#pragma once

#include <vector>
#include "Entity.h"
#include "Player.h"

#include "Level.h"

class LevelManager
{
public:
    std::vector<Entity*> entityList;
    Player *player = nullptr;
    Level *currentLevel = nullptr;

    SDL_Rect camera;

public:
    LevelManager();
       
    void drawLevel(SDL_Renderer *renderer);

    void checkCollisionX(Entity *entity);
    void checkCollisionY(Entity *entity);
    void changeLevel(Level *level);

    int getCameraOffsetX();
    int getCameraOffsetY();
};

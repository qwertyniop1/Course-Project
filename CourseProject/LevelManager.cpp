#include "LevelManager.h"

LevelManager::LevelManager()
{
    camera = { 0, 0, };    
}

void LevelManager::checkCollisionX(Entity * entity)
{
    for (int i = entity->getRect().y / TILE_SIZE; i < (entity->getRect().y + entity->getRect().h - 1) / TILE_SIZE + 1; ++i) {
        for (int j = entity->getRect().x / TILE_SIZE; j < (entity->getRect().x + entity->getRect().w) / TILE_SIZE + 1; ++j) {
            if (currentLevel->getMap()[i][j] == 'S') {                  
                if (entity->getDX() > 0) 
                    entity->setPosition(j * TILE_SIZE - entity->getRect().w - 1, entity->getRect().y);
                if (entity->getDX() < 0) 
                    entity->setPosition(j * TILE_SIZE + TILE_SIZE, entity->getRect().y);                          
            }
        }
    }
}

void LevelManager::checkCollisionY(Entity * entity)
{
    for (int i = entity->getRect().y / TILE_SIZE; i < (entity->getRect().y + entity->getRect().h/**/-1) / TILE_SIZE + 1; ++i) {
        for (int j = entity->getRect().x / TILE_SIZE; j < (entity->getRect().x + entity->getRect().w) / TILE_SIZE + 1; ++j) {
            if (currentLevel->getMap()[i][j] == 'S') {
                if (entity->getDY() > 0) {
                    entity->setPosition(entity->getRect().x, i * TILE_SIZE - entity->getRect().h);
                    entity->setDY(0);
                    entity->setOnGround(true);
                }
                if (entity->getDY() < 0) {
                    entity->setPosition(entity->getRect().x, i * TILE_SIZE + TILE_SIZE);
                    entity->setDY(0);
                }
            }
        }
    }

   /* if (entity->getRect().x >  WINDOW_WIDTH / 2) camera.x = entity->getRect().x - WINDOW_WIDTH / 2;
    if (entity->getRect().y <  WINDOW_HEIGTH / 2 + 50) camera.y = entity->getRect().y - WINDOW_HEIGTH / 2;*/
}

int LevelManager::getCameraOffsetX()
{
    return camera.x;
}

int LevelManager::getCameraOffsetY()
{
    return camera.y;
}

void LevelManager::drawLevel(SDL_Renderer * renderer)
{
    //if (tile.getHeight() == 0)
     //   tile.loadTexture(renderer, "res/tile.png");
    for (int i = 0; i < currentLevel->getHeigth(); ++i) {
        for (int j = 0; j < currentLevel->getWidth(); ++j) {
            if (currentLevel->getMap()[i][j] == 'S') {               
                currentLevel->getTexture(0)->render(renderer, j * TILE_SIZE - camera.x, i * TILE_SIZE - camera.y);
            }
            if (currentLevel->getMap()[i][j] == 'D') {   
                currentLevel->getTexture(1)->render(renderer, j * TILE_SIZE - camera.x, i * TILE_SIZE - camera.y);
            }
            if (currentLevel->getMap()[i][j] == ' ') continue;
                
            
        }        
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

#include "Level.h"

Level::Level()
{
    currentRect = { 0, 0, TILE_SIZE, TILE_SIZE }; // tmp
}

void Level::drawLevel(SDL_Renderer * renderer)
{
    for (int i = 0; i < H; ++i) {        
        for (int j = 0; j < W; ++j) {
            if (tileMap[i][j] == 'S') {
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            }   
            if (tileMap[i][j] == 'C') {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            if (tileMap[i][j] == ' ') continue;
            currentRect.x = j * TILE_SIZE;
            SDL_RenderFillRect(renderer, &currentRect);
        }
        currentRect.y = i * TILE_SIZE;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

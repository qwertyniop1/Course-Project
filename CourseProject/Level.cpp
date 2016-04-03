#include "Level.h"

Level::Level(SDL_Renderer * renderer)
{
    levelHeigth = H;
    levelWidth = W;

    tile.loadTexture(renderer, "res/tile.png");
    tile_2.loadTexture(renderer, "res/tile2.png");
}

std::string * Level::getMap()
{
    return tileMap;
}

int Level::getHeigth()
{
    return levelHeigth;
}

int Level::getWidth()
{
    return levelWidth;
}

Texture * Level::getTexture(int id = 0)
{
    if (!id) return &tile;
    return &tile_2;
}

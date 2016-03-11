#include "Entity.h"

bool Entity::load(FILE_PATH path, SDL_Renderer *renderer)
{
    sprite = new Texture();
    if (!sprite->loadTexture(renderer, path)) {
        return false;
    }
    
    height = sprite->getHeight();
    weigth = sprite->getWidth();

    textureRect = { 0, 0, weigth, height };

    return true;
}

void Entity::move()
{
}

void Entity::animate()
{
}

void Entity::render(SDL_Renderer *renderer)
{
    sprite->render(renderer, x, y, &textureRect);
}

void Entity::cleanup()
{
    sprite->free();
}

void Entity::setTextureRect(int x, int y, int height, int weigth)
{
    textureRect = { x, y, height, weigth };
}

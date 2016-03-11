#include "Entity.h"

bool Entity::load(FILE_PATH path, SDL_Renderer *renderer)
{
    sprite = new Texture();
    if (!sprite->loadTexture(renderer, path)) {
        return false;
    }
    
    height = sprite->getHeight();
    width = sprite->getWidth();
    x = 0;
    y = 0;

    textureRect = { 0, 0, width, height };

    return true;
}

void Entity::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Entity::animate()
{
    animControl.onAnimate();
}

void Entity::render(SDL_Renderer *renderer)
{
    textureRect.x = animControl.getCurrentFrame() * textureRect.w + 15; ////////////////////////////////////////////
    textureRect.y = animState * textureRect.h;
    sprite->render(renderer, x, y, &textureRect);
}

void Entity::cleanup()
{
    sprite->free();
}

void Entity::setTextureRect(int x, int y, int width, int height)
{
    textureRect = { x, y, width, height };
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::setMaxFrame(int frames)
{
    animControl.setFramesQuantity(frames);
}

void Entity::setAnimState(int state)
{
    animState = state;
}

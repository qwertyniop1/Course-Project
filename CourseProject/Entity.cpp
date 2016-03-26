#include "Entity.h"

bool Entity::load(FILE_PATH path, SDL_Renderer *renderer, SDL_Color *colorKey)
{
    sprite = new Texture();   

    if (colorKey == NULL) {
        if (!sprite->loadTexture(renderer, path)) {
            return false;
        }
    }
    else {
        if (!sprite->loadTexture(renderer, path, colorKey)) {
            return false;
        }
    }
    
    height = sprite->getHeight();
    width = sprite->getWidth();
    x = 0;
    y = 0;

    textureRect = { 0, 0, width, height };

    return true;
}

void Entity::move()
{
    x += dx;
    y += dy;
}

void Entity::move(int dx, int dy)
{

}

void Entity::animate()
{
    animControl.onAnimate();
}

void Entity::render(SDL_Renderer *renderer)
{
    textureRect.x = startX + animControl.getCurrentFrame() * textureRect.w;
    textureRect.y = startY + animState * textureRect.h;
    sprite->render(renderer, x, y, &textureRect, 0.0, NULL, (SDL_RendererFlip)orientation);
}

void Entity::cleanup()
{
    sprite->free();
}
/*
void Entity::checkCollision()
{

}*/

void Entity::setTextureRect(int x, int y, int width, int height)
{
    textureRect = { x, y, width, height };
    startX = x;
    startY = y;
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

void Entity::setOrientation(Direction dir)
{
    orientation = dir;
}

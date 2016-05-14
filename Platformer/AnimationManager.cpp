#include "AnimationManager.h"

void AnimationManager::create(sf::String name, sf::Texture &texture, int x, int y, int width, int height, int count, double speed, int step)
{
    animationsList[name] = Animation(texture, x, y, width, height, count, speed, step);
    currentAnimation = name;
}

void AnimationManager::draw(sf::RenderWindow & window, int x, int y)
{
    animationsList[currentAnimation].sprite.setPosition(x, y);
    window.draw(animationsList[currentAnimation].sprite);
}

void AnimationManager::set(sf::String name)
{
    currentAnimation = name;
}

void AnimationManager::flip(bool flag)
{
    animationsList[currentAnimation].isFlip = flag;
}

void AnimationManager::tick(double time)
{
    animationsList[currentAnimation].tick(time);
}

void AnimationManager::play()
{
    animationsList[currentAnimation].isPlaying = true;
}

void AnimationManager::pause()
{
    animationsList[currentAnimation].isPlaying = false;
}

double AnimationManager::getHeight()
{
    return animationsList[currentAnimation].frames[animationsList[currentAnimation].currentFrame].height;
}

double AnimationManager::getWidth()
{
    return animationsList[currentAnimation].frames[animationsList[currentAnimation].currentFrame].width;
}
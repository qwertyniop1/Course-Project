#include "Animation.h"

Animation::Animation(sf::Texture & texture, int x, int y, int width, int height, int count, double speed, int step)
{
    this->speed = speed;
    sprite.setTexture(texture);
    currentFrame = 0;
    isPlaying = true;
    isFlip = false;

    for (size_t i = 0; i < count; ++i) {
        frames.push_back(sf::IntRect(x + i * step, y, width, height));
        framesFlip.push_back(sf::IntRect(x + i * step + width, y, -width, height));
    }
}

void Animation::tick(double time)
{
    if (!isPlaying) {
        return;
    }

    currentFrame += speed * time;
    if (currentFrame > frames.size()) {
        currentFrame = 0;
    }

    int frame = /*(int)*/ currentFrame;
    if (isFlip) {
        sprite.setTextureRect(framesFlip[frame]);
    } 
    else {
        sprite.setTextureRect(frames[frame]);
    }
}

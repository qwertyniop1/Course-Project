#include "Animation.h"

Animation::Animation(sf::Texture & texture, double speed)
{
    this->speed = speed;
    sprite.setTexture(texture);
    currentFrame = 0;
    isPlaying = true;
    isFlip = false;
}

void Animation::tick(double time)
{
    if (!isPlaying) {
        return;
    }

    currentFrame += speed * time;
    if (currentFrame >= frames.size()) {
        currentFrame = 0;
    }

    int frame = (int)currentFrame;
    if (isFlip) {
        sprite.setTextureRect(framesFlip[frame]);
    } 
    else {
        sprite.setTextureRect(frames[frame]);
    }
}




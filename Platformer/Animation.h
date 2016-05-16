#pragma once

#include "Global.h"

class Animation
{
    friend class AnimationManager;

public:
    Animation() {};
    Animation(sf::Texture & texture, double speed);

    void tick(double time);

private:
    std::vector<sf::IntRect> frames, framesFlip;
    double currentFrame, speed;
    bool isFlip, isPlaying;
    sf::Sprite sprite;

};
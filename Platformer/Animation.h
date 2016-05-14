#pragma once

#include "Global.h"

class Animation
{
public:
    std::vector<sf::IntRect> frames, framesFlip;
    double currentFrame, speed;
    bool isFlip, isPlaying;
    sf::Sprite sprite;

    Animation() {};
    Animation(sf::Texture & texture, int x, int y, int width, int height, int count, double speed, int step);
    
    void tick(double time);

private:

};

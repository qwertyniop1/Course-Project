#pragma once

#include "Graphic.h"

class Animation {
private:
    int currentFrame;
    int frameInc;
    int frameRate;
    long oldTime;
    int maxFrames;

public:    
    bool oscillate;

    Animation();
    void onAnimate();
    void setFrameRate(int rate);
    void setCurrentFrame(int frame);
    void setFramesQuantity(int frames);
    int getCurrentFrame();
};
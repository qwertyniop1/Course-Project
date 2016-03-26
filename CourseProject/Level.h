#pragma once

#include "Graphic.h"
#include <string>

const int H = 12;
const int W = 40;
const int TILE_SIZE = WINDOW_HEIGTH / H;

class Level {
private:    
    std::string tileMap[H] = {
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
        "SS   S                               SSS",
        "SS   S                                SS",
        "SS   S                                SS",
        "SS   S                                SS",
        "SS       C C C                        SS",
        "SS                 SSSSSSSSSSSSSSSSSSSSS",
        "SS                 SSSSSSSSSSSSSSSSSSSSS",
        "SS                                    SS",
        "SS                                    SS",
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    };
    SDL_Rect currentRect;

public:
    Level();
    void drawLevel(SDL_Renderer *renderer);

};

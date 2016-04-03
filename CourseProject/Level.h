#pragma once

#include "Graphic.h"
#include <string>
#include "Texture.h"

const int H = 20;
const int W = 80;
const int TILE_SIZE = 32;

class Level {
private:    
    std::string tileMap[H] = {
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
        "SS   S                               SSSSS   S                               SSS",
        "SS   S                                SSSS   S                               SSS",
        "SS   S                                                                       SSS",
        "SS   S                                                                       SSS",
        "SS       C C C                                                               SSS",
        "SS                 SSSSSSSSSSSSSSSSSSSSSSS                                   SSS",
        "SS                 SSSSSSSSSSSSSSSSSSSSSSS                                   SSS",
        "SS                                                                           SSS",
        "SS                                                                           SSS",
        "SS                                                                           SSS",
        "SS     SS    SSSSSSSSS                SSSS SSSS                              SSS",
        "SS                                    SSSS   SSS                             SSS",
        "SS                                    SSSS   S SS                            SSS",
        "SS                      SS            SSSS   S  SS                           SSS",
        "SS                    SSS             SSSS   S   SS                          SSS",
        "SS                  SSS               SSSS   S    SS                         SSS",
        "SS                SSS                 SSSS   S            DDDDDDDDDDDDD      SSS",
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    };
   
    int levelHeigth;
    int levelWidth;

    Texture tile;
    Texture tile_2;

public:
    Level(SDL_Renderer *renderer);
    
    std::string* getMap();
    int getHeigth();
    int getWidth();
    Texture* getTexture(int id);

};

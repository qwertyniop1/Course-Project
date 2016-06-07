#ifndef GLOBAL_H
#define GLOBAL_H 

#include <SFML/Graphics.hpp>
//#include <vld.h>
#include <iostream>

const int DEFAULT_WINDOW_HEIGHT = 600; //600
const int DEFAULT_WINDOW_WIDTH = 800; //800

const std::string APPLICATION_TITLE = "Aladdin beta";

enum CollisionDirection
{
    X, Y
};

enum Direction {
    Normal, Flip
};

void setAndScale(sf::Sprite &sprite, sf::Texture &texture, int width, int height);

#endif


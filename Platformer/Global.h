#pragma once

#include <SFML\Graphics.hpp>

enum CollisionDirection
{
    X, Y
};


const int HEIGHT = 12; //tmp
const int WIDTH = 40;

const sf::String tileMap[HEIGHT] = {

    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B         0000                BBBB     B",
    "B              BB                B     B",
    "BBB                              B     B",
    "B                                BB    B",
    "B              BB                      B",
    "B    B   BBB   BB                      B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};

extern double offsetX, offsetY;

enum Direction {
    Normal, Flip
};



#pragma once

#include <SFML\Graphics.hpp>

enum Direction
{
    X, Y
};

class Player {
public:
    double dx, dy;
    sf::FloatRect rect;
    bool onSurface;
    sf::Sprite sprite;
    double currentFrame;

    Player(sf::Texture &image);

    void update(double time);
    void Player::collision(Direction dir);
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
    "B                                B     B",
    "BBB                              B     B",
    "B              BB                BB    B",
    "B              BB                      B",
    "B    B         BB         BB           B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};

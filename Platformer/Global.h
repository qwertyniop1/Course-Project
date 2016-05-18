#pragma once

#include <SFML\Graphics.hpp>
#include <vld.h>
#include <iostream>

const int DEFAULT_WINDOW_HEIGHT = 600;
const int DEFAULT_WINDOW_WIDTH = 800;

static const std::string menuTexturesPath[] = { "play.png", "highscores.png", "settings.png", "exit.png" };

enum CollisionDirection
{
    X, Y
};

enum Direction {
    Normal, Flip
};



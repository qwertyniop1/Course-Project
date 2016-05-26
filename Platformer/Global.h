#pragma once

#include <SFML\Graphics.hpp>
//#include <vld.h>
#include <iostream>

const int DEFAULT_WINDOW_HEIGHT = 600;
const int DEFAULT_WINDOW_WIDTH = 800;

static const std::string menuTexturesPath[] = { "play.png", "highscores.png", "settings.png", "exit.png" };
const std::string APPLICATION_TITLE = "Game without name v. 1.1 beta";

enum CollisionDirection
{
    X, Y
};

enum Direction {
    Normal, Flip
};



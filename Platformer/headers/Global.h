#ifndef GLOBAL_H
#define GLOBAL_H 

#include <SFML/Graphics.hpp>
//#include <vld.h>
#include <iostream>

#define TRY_CHANGE_STATE(state) { \
            try { \
                stateManager->changeState(state); \
            } \
            catch (std::runtime_error &err) { \
                stateManager->quit(); \
            } \
}

#define TRY_LOAD(expression, message) { \
            if (!expression) { \
                std::cout << message << std::endl; \
                return false; \
            } \
}

#define LOAD_TEXTURE(expression) { \
            TRY_LOAD(expression, "Can't load texture from file"); \
}

#define LOAD_ANIMATION(expression) { \
            TRY_LOAD(expression, "Can't load animation from file"); \
}

#define LOAD_FONT(expression) { \
            TRY_LOAD(expression, "Can't load font"); \
}

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



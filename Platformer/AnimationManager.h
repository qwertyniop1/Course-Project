#pragma once

#include "Global.h"
#include "Animation.h"
#include "TinyXML\tinyxml.h"

#include <string>

class AnimationManager
{
public:
    AnimationManager() {};
    ~AnimationManager();

    void create(sf::String name, sf::Texture &texture, int x, int y, int width, int height, int count, double speed, int step);

    void draw(sf::RenderWindow &window, int x = 0, int y = 0);

    void set(sf::String name);

    void flip(bool flag);

    void tick(double time);

    void play();

    void pause();

    double getHeight();

    double getWidth();

    void loadFromXML(std::string fileName, sf::Texture &texture);

private:
    sf::String currentAnimation;
    std::map<sf::String, Animation> animationsList;

};

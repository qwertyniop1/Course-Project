#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "Animation.h"
#include "TinyXML/tinyxml.h"

class AnimationManager {
public:
    AnimationManager() {};

    ~AnimationManager();

    void create(sf::String name,
                sf::Texture &texture,
                int x,
                int y,
                int width,
                int height,
                int count,
                double speed,
                int step);

    void draw(sf::RenderWindow &window, int x = 0, int y = 0);

    void set(sf::String name);

    void flip(bool flag);

    void tick(double time);

    void play();

    void pause();

    double getHeight();

    double getWidth();

    bool loadFromXML(std::string fileName, sf::Texture &texture);

private:
    sf::String currentAnimation;
    std::map<sf::String, Animation> animationsList;
};

#endif

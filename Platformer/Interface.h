#pragma once

#include "Global.h"

class Label {
protected:
    double x, y;
    sf::Text labelText;
    std::string text;

public:
    void create(std::string text, sf::Font &font, double x = 0, double y = 0);
    sf::Text displayText();
    sf::FloatRect getBounds();
    void setPosition(int x, int y);
};
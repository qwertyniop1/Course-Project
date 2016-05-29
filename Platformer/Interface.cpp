#include "Interface.h"

void Label::create(std::string text, sf::Font &font, double x, double y)
{
    this->x = x;
    this->y = y;
    this->text = text;
    labelText.setColor(sf::Color::White);
    labelText.setFont(font);
    labelText.setCharacterSize(48);
    labelText.setPosition(x, y);
    labelText.setString(text);
}

sf::Text Label::displayText()
{
    labelText.setString(text); 
    return labelText;
}

sf::FloatRect Label::getBounds()
{
    return labelText.getGlobalBounds();
}

void Label::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    labelText.setPosition(x, y);
}

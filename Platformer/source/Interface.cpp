#include "Interface.h"

void Label::create(std::wstring text, sf::Font &font, double x, double y) {
    this->x = x;
    this->y = y;
    this->text = text;
    labelText.setColor(sf::Color::White);
    labelText.setFont(font);
    labelText.setCharacterSize(48);
    labelText.setPosition(x, y);
    labelText.setString(text);
}

sf::Text Label::displayText() {
    labelText.setString(L"");
    labelText.setString(text);
    return labelText;
}

sf::FloatRect Label::getBounds() {
    return labelText.getGlobalBounds();
}

void Label::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    labelText.setPosition(x, y);
}

void Label::setText(std::wstring text) {
    this->text = text;
}

void Label::setFontColor(sf::Color color) {
    labelText.setColor(color);
}

void Button::create(std::wstring text,
                    sf::Font &font,
                    double x,
                    double y,
                    double width,
                    double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->text = text;
    labelText.setColor(sf::Color::White);
    labelText.setFont(font);
    labelText.setCharacterSize(20);
    labelText.setPosition(x, y);
    labelText.setString(text);

    box.setSize(sf::Vector2f(width, height));
    box.setPosition(x, y);
    box.setFillColor(sf::Color(133, 133, 133));
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color(66, 66, 66));
}

sf::RectangleShape Button::displayButton() {
    return box;
}

bool Button::select(sf::Vector2i mouse) {
    return (mouse.x > x && mouse.x < x + width) && (mouse.y > y && mouse.y < y + height);
}

sf::FloatRect Button::getBounds() {
    return box.getGlobalBounds();
}

sf::FloatRect Button::getTextBounds() {
    return labelText.getGlobalBounds();
}

void Button::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    labelText.setPosition(x, y);
    box.setPosition(x, y);
}

void Button::setSize(int width, int height) {
    this->width = width;
    this->height = height;
    box.setSize(sf::Vector2f(width, height));
}

void Button::setCharacterSize(int size) {
    labelText.setCharacterSize(size);
}

void Button::setFillColor(sf::Color color) {
    box.setFillColor(color);
}

void Button::setBoundsColor(sf::Color color) {
    box.setOutlineColor(color);
}

void Input::create(sf::Font &font,
                   std::wstring _text,
                   double _x,
                   double _y,
                   double _width,
                   double _height) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    text = _text;
    focus = false;

    labelText.setFont(font);
    labelText.setCharacterSize(20);
    labelText.setColor(sf::Color::Black);
    labelText.setPosition(x, y);
    labelText.setString(text);

    box.setSize(sf::Vector2f(width, height));
    box.setPosition(x, y);
    box.setFillColor(sf::Color::White);
}

void Input::reText(wchar_t _tmp) {
    text.erase(text.size() - 1);

    if (_tmp != 8) {
        if (text.length() > 10) return;
        text += _tmp;
    }
    else {
        if (text.size() > 0) {
            text.erase(text.size() - 1);
        }

    }
    text += L"|";
    labelText.setString(text);
}

bool Input::select() {
    return focus;
}

bool Input::select(sf::Vector2i _mouse) {
    if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
        focus = true;
        text += L"|";
    } else {
        if (text.size() > 0) {
            if (text[text.size() - 1] == 124) {
                text.erase(text.size() - 1);
            }
        }
        focus = false;
    }
    return focus;
}

std::wstring Input::readText() {
    if (text.size() != 0 && text[text.size() - 1] == 124) {
        text.erase(text.size() - 1);
    }
    return text;
}

sf::FloatRect Input::getBounds() {
    return box.getGlobalBounds();
}

void Input::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    labelText.setPosition(x, y);
    box.setPosition(x, y);
}

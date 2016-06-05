#pragma once

#include "Global.h"

class Label {
protected:
    double x, y;
    sf::Text labelText;
    std::wstring text;

public:
    virtual void create(std::wstring text, sf::Font &font, double x = 0, double y = 0);
    sf::Text displayText();
    sf::FloatRect getBounds();
    void setPosition(int x, int y);
    void setText(std::wstring text);
    void setFontColor(sf::Color color);
};

class Button : public Label {
protected:
    double width, height;
    sf::RectangleShape box;

public:
    void create(std::wstring text, sf::Font &font, double x = 0, double y = 0, double width = 150, double height = 30);
    sf::RectangleShape displayButton();
    bool select(sf::Vector2i mouse);
    sf::FloatRect getBounds();
    sf::FloatRect getTextBounds();
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setCharacterSize(int size);
    void setFillColor(sf::Color color);
    void setBoundsColor(sf::Color color);
};

class Input : public Button {
protected:
    bool focus;
public:
    void create(sf::Font &font, std::wstring _text = L"", double _x = 0, double _y = 0, double _width = 150, double _height = 30);
    void reText(wchar_t _tmp);

    // Проверка Фокуса Input
    bool select();

    // Установка Фокуса Input
    bool select(sf::Vector2i _mouse);

    //Для того, что бы считать текст с поля Ipnut необходимо пременить  readText() который возвращает string
    std::wstring readText();
    sf::FloatRect getBounds();
    void setPosition(int x, int y);
};
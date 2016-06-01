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

void Button::create(std::string text, sf::Font & font, double x, double y, double width, double height)
{
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

    box.setSize(sf::Vector2f(width, height));		// размер кнопки
    box.setPosition(x, y);						// координаты кнопки
    box.setFillColor(sf::Color(133, 133, 133));	// цвет кнопки
    box.setOutlineThickness(2);					// Контур X пикселей
    box.setOutlineColor(sf::Color(66, 66, 66));
}

sf::RectangleShape Button::displayButton()
{
    return box;
}

bool Button::select(sf::Vector2i mouse)
{
    if ((mouse.x > x && mouse.x < x + width) && (mouse.y > y && mouse.y < y + height)) {
        return  true;
    }
    return false;
}

void Input::create(sf::Font &font, std::string _text, double _x, double _y, double _width, double _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    text = _text;								// загружает текст
    focus = false;								// фокус поля ввода

    labelText.setFont(font);							// загружаем фрифт
    labelText.setCharacterSize(20); 					// в пикселях, а не точках!
    labelText.setColor(sf::Color::Black);					// устанавливаем цвет выводимого текста
    labelText.setPosition(x, y);						// позиция текста
    labelText.setString(text);

    box.setSize(sf::Vector2f(width, height));		// размер поля ввода
    box.setPosition(x, y);						// координаты поля ввода
    box.setFillColor(sf::Color::White);	// цвет кнопки
}

void Input::reText(char _tmp)
{
    if (text.length() > 10) return;
    text.erase(text.size() - 1);

    if (_tmp != 8) {
        text += _tmp;
    }
    else {
        if (text.size() > 0) {
            text.erase(text.size() - 1);
        }

    }
    text += "|";
    labelText.setString(text);
}

bool Input::select()
{
    return focus;
}

bool Input::select(sf::Vector2i _mouse)
{
    if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) { 	//Если нажат клаиша над объектом Input...
        focus = true;																	   	// Фокус true
        text += "|";																		// В конец строки добаляем | (что бы понимать что input в фокусе)
    }
    else {																				//...Иначе если нажатие произошло не над объектом, то...
        if (text.size() > 0) {																// проверка последнего символа(иначе вылетает)
            if (text[text.size() - 1] == 124) {													// если символ | ...
                text.erase(text.size() - 1);														// ... то удаляем его
            }
        }
        focus = false;																		// устанавливаем фокус false
    }
    return focus;
}

std::string Input::readText()
{    
    if (text.size() != 0 && text[text.size() - 1] == 124) { 	// удаляем (если есть) символ |
        text.erase(text.size() - 1);
    }
    return text;   
}

sf::FloatRect Input::getBounds()
{
    return box.getGlobalBounds();
}

void Input::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    labelText.setPosition(x, y);
    box.setPosition(x, y);
}

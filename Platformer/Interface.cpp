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

    box.setSize(sf::Vector2f(width, height));		// ������ ������
    box.setPosition(x, y);						// ���������� ������
    box.setFillColor(sf::Color(133, 133, 133));	// ���� ������
    box.setOutlineThickness(2);					// ������ X ��������
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
    text = _text;								// ��������� �����
    focus = false;								// ����� ���� �����

    labelText.setFont(font);							// ��������� �����
    labelText.setCharacterSize(20); 					// � ��������, � �� ������!
    labelText.setColor(sf::Color::Black);					// ������������� ���� ���������� ������
    labelText.setPosition(x, y);						// ������� ������
    labelText.setString(text);

    box.setSize(sf::Vector2f(width, height));		// ������ ���� �����
    box.setPosition(x, y);						// ���������� ���� �����
    box.setFillColor(sf::Color::White);	// ���� ������
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
    if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) { 	//���� ����� ������ ��� �������� Input...
        focus = true;																	   	// ����� true
        text += "|";																		// � ����� ������ �������� | (��� �� �������� ��� input � ������)
    }
    else {																				//...����� ���� ������� ��������� �� ��� ��������, ��...
        if (text.size() > 0) {																// �������� ���������� �������(����� ��������)
            if (text[text.size() - 1] == 124) {													// ���� ������ | ...
                text.erase(text.size() - 1);														// ... �� ������� ���
            }
        }
        focus = false;																		// ������������� ����� false
    }
    return focus;
}

std::string Input::readText()
{    
    if (text.size() != 0 && text[text.size() - 1] == 124) { 	// ������� (���� ����) ������ |
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

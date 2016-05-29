#include "Application.h"

int main()
{
    Application application;

    return application.onExecute();
}

void setAndScale(sf::Sprite &sprite, sf::Texture &texture)
{
    sprite.setTexture(texture);

    double coef = (double)DEFAULT_WINDOW_HEIGHT / texture.getSize().y;
    sprite.setScale(coef, coef);
    sprite.move((DEFAULT_WINDOW_WIDTH - texture.getSize().x * coef) / 2, 0);
}
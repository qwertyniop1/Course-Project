# include "Global.h"

void setAndScale(sf::Sprite &sprite, sf::Texture &texture, int width, int height)
{
    sprite.setTexture(texture);

    double coef = (double)height / texture.getSize().y;
    sprite.setScale(coef, coef);
    sprite.move((width - texture.getSize().x * coef) / 2, 0);
}
#include "Player.h"

#define SURFACE 350 // TODO delete

Player::Player(sf::Texture & image)
{
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 244, 40, 50));
    rect = sf::FloatRect(0, 0, 40, 50);
    dx = 0;
    dy = 0;
    currentFrame = 0;
}

void Player::update(double time)
{
    rect.left += dx * time;

    if (!onSurface) {
        dy += 0.0005 * time;
    }
    rect.top += dy * time;

    onSurface = false;
    if (rect.top > SURFACE) {
        rect.top = SURFACE;
        dy = 0;
        onSurface = true;
    }

    currentFrame += 0.005 * time;
    if (currentFrame > 6) currentFrame = 0;

    if (dx > 0) {
        sprite.setTextureRect(sf::IntRect(int(currentFrame) * 40, 244, 40, 50));
    }
    if (dx < 0) {
        sprite.setTextureRect(sf::IntRect(int(currentFrame) * 40 + 40, 244, -40, 50));
    }
    dx = 0;

    sprite.setPosition(rect.left, rect.top);
}

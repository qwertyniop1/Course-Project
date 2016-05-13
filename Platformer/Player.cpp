#include "Player.h"

Player::Player(sf::Texture & image)
{
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 244, 40, 50));
    rect = sf::FloatRect(50, 50, 40, 50);
    dx = 0;
    dy = 0;
    currentFrame = 0;
}

void Player::update(double time)
{
    rect.left += dx * time;
    collision(X);

    if (!onSurface) {
        dy += 0.0005 * time;
    }
    rect.top += dy * time;
    onSurface = false;
    collision(Y);   

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

void Player::collision(Direction dir)
{
    for (size_t i = rect.top / 32; i < (rect.top + rect.height) / 32; ++i) {
        for (size_t j = rect.left / 32; j < (rect.left + rect.width) / 32; ++j) {
            if (tileMap[i][j] == 'B') {
                if (dir == X) {
                    if (dx > 0) {
                        rect.left = j * 32 - rect.width;
                    }
                    if (dx < 0) {
                        rect.left = j * 32 + 32;
                    }
                }
                if (dir == Y) {
                    if (dy > 0) {
                        rect.top = i * 32 - rect.height;
                        dy = 0;
                        onSurface = true;
                    }
                    if (dy < 0) {
                        rect.top = i * 32 + 32;
                        dy = 0;
                    }
                }
            }
        }
    }
}

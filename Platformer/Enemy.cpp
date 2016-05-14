#include "Enemy.h"

Enemy::Enemy(sf::Texture & image, int x, int y)
{
    sprite.setTexture(image);
    rect = sf::FloatRect(x, y, 32, 32);

    dx = 0.05;
    currentFrame = 0;
    isAlive = true;
}

void Enemy::update(double time)
{
    rect.left += dx * time;
    collision(X);

    currentFrame += 0.005 * time;
    if (currentFrame > 6) currentFrame = 0;

    if (dx > 0) {
        sprite.setTextureRect(sf::IntRect(int(currentFrame) * 40, 244, 40, 50));
    }
    if (dx < 0) {
        sprite.setTextureRect(sf::IntRect(int(currentFrame) * 40 + 40, 244, -40, 50));
    }
    
    if (!isAlive) {
        //sprite.setTextureRect(sf::IntRect())
    }

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

void Enemy::collision(Direction dir)
{
    for (size_t i = rect.top / 32; i < (rect.top + rect.height) / 32; ++i) {
        for (size_t j = rect.left / 32; j < (rect.left + rect.width) / 32; ++j) {

            if (tileMap[i][j] == 'B') {
                if (dir == X) {
                    if (dx > 0) {
                        rect.left = j * 32 - rect.width;
                        dx *= -1;
                    }
                    else if (dx < 0) {
                        rect.left = j * 32 + 32;
                        dx *= -1;
                    }
                }
            }
        }
    }
}

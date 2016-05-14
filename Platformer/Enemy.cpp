#include "Enemy.h"

Enemy::Enemy(AnimationManager &manager, int x, int y) : Entity(manager, x, y)
{
    name = "Enemy";
}

void Enemy::update(double time)
{
    x += dx * time;
    collision(X);
    
    animationManager.tick(time);
}

void Enemy::collision(CollisionDirection dir)
{
    for (size_t i = y / 32; i < (y + height) / 32; ++i) {
        for (size_t j = x / 32; j < (x + width) / 32; ++j) {
            if (tileMap[i][j] == 'B') {
                if (dir == X) {
                    if (dx > 0) {
                        x = j * 32 - width;
                        dx *= -1;
                    }
                    else if (dx < 0) {
                        x = j * 32 + 32;
                        dx *= -1;
                    }
                }
            }
        }
    }
}

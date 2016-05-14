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
    // collision detection
}

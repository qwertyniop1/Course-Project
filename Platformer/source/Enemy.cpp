#include "Enemy.h"

Enemy::Enemy(AnimationManager &manager, int x, int y, Level &level) : Entity(manager, x, y, level)
{
    name = "Enemy";
    animationManager.set("walk");
    dx = ENEMY_SPEED;
}

void Enemy::update(double time)
{
    if (direction == Direction::Flip) {
        animationManager.flip(true);
    }
    else {
        animationManager.flip(false);
    }

    x += dx * time;
    collision(X);

    dy += ACCELERATION * time;
    y += dy * time;
    collision(Y);
    
    animationManager.tick(time);
}

void Enemy::collision(CollisionDirection dir)
{
    std::vector<Object> objects = level.getAllObjects();
    for (size_t i = 0; i < objects.size(); ++i) {
        if (getRect().intersects(objects[i].rect)) {
            if (objects[i].name == "solid" || objects[i].name == "e_solid") {
                if (dir == CollisionDirection::X) {
                    if (dx > 0) {
                        x = objects[i].rect.left - width;     
                        direction = Direction::Flip;
                    }
                    if (dx < 0) {
                        x = objects[i].rect.left + objects[i].rect.width;
                        direction = Direction::Normal;
                    }
                    dx *= -1;
                }
                if (dir == CollisionDirection::Y) {
                    if (dy > 0) {
                        y = objects[i].rect.top - height;
                        dy = 0;                        
                    }
                    if (dy < 0) {
                        y = objects[i].rect.top + objects[i].rect.height;
                        dy = 0;
                    }
                }
            }
        }
    }
}

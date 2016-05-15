#include "Player.h"

Player::Player(AnimationManager &manager, int x, int y, Level &level) : Entity(manager, x, y, level)
{    
    currentState = State::Stay;
}

void Player::handleKeys()
{
    if (keys[Key::Left]) {
        direction = Direction::Flip;
        if (currentState != State::Duck) {
            dx = -0.1;
        }
        if (currentState == State::Stay) {
            currentState = State::Walk;
        }
    }
    if (keys[Key::Right]) {
        direction = Direction::Normal;
        if (currentState != State::Duck) {
            dx = 0.1;
        }
        if (currentState == State::Stay) {
            currentState = State::Walk;
        }
    }
    if (keys[Key::Up]) {
        if (currentState == State::Climb || currentState == State::Swim) {
            dy = -0.05;
        }
        if (currentState == State::Stay || currentState == State::Walk) {
            dy = -0.27;
            currentState = State::Jump;
        }
    }
    if (keys[Key::Down]) {
        if (currentState == State::Climb || currentState == State::Swim) {
            dy = 0.05;
        }
        if (currentState == State::Stay || currentState == State::Walk) {
            dx = 0;
            currentState = State::Duck;
        }
    }
    if (keys[Key::Space]) {
        isShooting = true;
    }

    if (!(keys[Key::Left] || keys[Key::Right])) {
        dx = 0;
        if (currentState == State::Walk) {
            currentState = State::Stay;
        }
    }
    if (!(keys[Key::Up] || keys[Key::Down])) {
        if (currentState == State::Climb || currentState == State::Swim) {
            dy = 0;
        }
    }
    if (!keys[Key::Down]) {
        if (currentState == State::Duck) {
            currentState = State::Stay;
        }
    }
    if (!keys[Key::Space]) {
        isShooting = false;
    }

}

void Player::update(double time)
{
    handleKeys();

    switch (currentState) {
    case State::Stay:
        animationManager.set("stay");
        break;
    case State::Walk:
        animationManager.set("walk");
        break;
    case State::Jump:
        animationManager.set("jump");
        break;
    case State::Duck:
        animationManager.set("duck");
        break;
    case State::Climb:
        animationManager.set("climb");        
        if (dy != 0) {
            animationManager.play();
        }
        else {
            animationManager.pause();
        }
        if (!isOnLadder) {
            currentState = State::Stay;
        }
        break;
    default:
        break;
    }

    if (isShooting) {
        animationManager.set("shoot");
        if (currentState == State::Walk) animationManager.set("shootandwalk");
    }

    if (direction == Direction::Flip) {
        animationManager.flip(true);
    }
    else {
        animationManager.flip(false);
    }

    if (currentState == State::Climb) {
        if (!isOnLadder) currentState = State::Stay;
    }
    else { 
        //dy += 0.0005*time; 
    }
    isOnLadder = false;

    x += dx * time;
    collision(X);

    dy += 0.0005 * time;
    y += dy * time;
    collision(Y);   

    animationManager.tick(time);

    for (std::map<Key, bool>::iterator it = keys.begin(); it != keys.end(); it++) {
        it->second = false;
    }
}

void Player::collision(CollisionDirection dir)
{
    std::vector<Object> objects = level.getAllObjects();
    for (size_t i = 0; i < objects.size(); ++i) {
        if (getRect().intersects(objects[i].rect)) {
            if (objects[i].name == "solid") {
                if (dir == CollisionDirection::X) {
                    if (dx > 0) {
                        x = objects[i].rect.left - width;
                    }
                    if (dx < 0) {
                        x = objects[i].rect.left + objects[i].rect.width;
                    }
                }
                if (dir == CollisionDirection::Y) {
                    if (dy > 0) {
                        y = objects[i].rect.top - height;  
                        dy = 0;   
                        currentState = State::Stay;
                    }
                    if (dy < 0) {
                        y = objects[i].rect.top + objects[i].rect.height; 
                        dy = 0;
                    }
                }                   
            }       

            if (objects[i].name == "ladder") {
                isOnLadder = true;
                if (currentState == State::Climb) {
                    x = objects[i].rect.left - 10;
                }

            }

        }
    }
}


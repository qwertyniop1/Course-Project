#include "Player.h"

Player::Player(AnimationManager &manager)
{
    animationManager = manager;
    currentState = State::Stay;

    rect.left = 50;
    rect.top = 100;
    rect.height = 50;
    rect.width = 40;
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
    }

    if (direction == Direction::Flip) {
        animationManager.flip(true);
    }
    else {
        animationManager.flip(false);
    }

    rect.left += dx * time;
    collision(X);

    dy += 0.0005 * time;
    rect.top += dy * time;
    collision(Y);   

    animationManager.tick(time);

    for (std::map<Key, bool>::iterator it = keys.begin(); it != keys.end(); it++) {
        it->second = false;
    }
}

void Player::collision(CollisionDirection dir)
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
                        currentState = State::Stay;
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

void Player::draw(sf::RenderWindow &window)
{
    animationManager.draw(window, rect.left - offsetX, rect.top - offsetY /*+ he*/);
}

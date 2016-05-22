#include "PlayState.h"

bool PlayState::onInit()
{
    view.reset(sf::FloatRect(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));

    if (!playerTexture.loadFromFile("res/fang.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    if (!bulletTexture.loadFromFile("res/bullet.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    if (!coinTexture.loadFromFile("res/coins.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    playerAnimation.loadFromXML("res/hero.xml", playerTexture); // check
    bulletAnimation.loadFromXML("res/bullet.xml", bulletTexture);
    coinAnimation.loadFromXML("res/coin.xml", coinTexture);
    
    // extract to another class (level)
    if (!level.loadFromFile("res/level2.tmx")) {
        std::cout << "Can't load level data" << std::endl;
        return false;
    }

    enemies = level.getObjects("enemy"); // check if necessary

    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Enemy(playerAnimation, enemies[i].rect.left, enemies[i].rect.top, level));
    }

    enemies = level.getObjects("coin"); // check if necessary

    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Coin(coinAnimation, enemies[i].rect.left, enemies[i].rect.top, level));
    }

    Object playerObject;
    try {
        playerObject = level.getObject("player");
    }
    catch (std::runtime_error) {
        std::cout << "Incorrect level data" << std::endl;
        return false;
    }
    player = new Player(playerAnimation, playerObject.rect.left, playerObject.rect.top, level);

    return true;
}

void PlayState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        stateManager->quit();
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(MenuState::getInstance(stateManager));
        }
        if (event.key.code == sf::Keyboard::Space) {
            entities.push_back(new Bullet(bulletAnimation, player->getRect().left, player->getRect().top + 10, player->getDirection(), level));
        }
    }
}

void PlayState::onLoop()
{
    double time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 800;
    if (time > 50) {
        time = 50;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player->keys[Player::Key::Left] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player->keys[Player::Key::Right] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player->keys[Player::Key::Up] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player->keys[Player::Key::Down] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player->keys[Player::Key::Space] = true;
    }

    player->update(time);

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ) {
        Entity *entity = *it;

        if (!entity->isAlive()) {
            it = entities.erase(it);
            delete entity;
        }
        else {
            it++;
        }
    }

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        (*it)->update(time);
    }

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        if ((*it)->getName() == "Enemy") {
            Entity *enemy = *it;
            if (!enemy->isAlive()) {
                continue;
            }
            if (player->getRect().intersects(enemy->getRect())) {
                if (player->dy > 0) {
                    enemy->dx = 0;
                    player->dy = -0.2;
                    enemy->eliminate();
                }
                else {
                    // kill player
                }
            }

            for (std::list<Entity*>::iterator _it = entities.begin(); _it != entities.end(); ++_it) {
                if ((*_it)->getName() == "Bullet") {
                    Entity *bullet = *_it;
                    if (bullet->isAlive()) {
                        if (bullet->getRect().intersects(enemy->getRect())) {
                            bullet->eliminate();
                            enemy->eliminate();
                        }
                    }
                }
            }
        }
        if ((*it)->getName() == "Coin") {
            if (player->getRect().intersects((*it)->getRect())) {
                std::cout << "+1" << std::endl;
                (*it)->eliminate();
            }
        }
    }
}

void PlayState::onRender(sf::RenderWindow &window)
{
    view.setCenter(player->getRect().left, player->getRect().top);
    window.setView(view);

    level.draw(window);

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        (*it)->draw(window);
    }

    player->draw(window);
}

void PlayState::onCleanup()
{
    enemies.clear();
    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        delete *it;
    }
    entities.clear();
    delete player;
}

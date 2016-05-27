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

    if (!font.loadFromFile("res/font.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    score = 0;
    scoreText.setFont(font);
    scoreText.setCharacterSize(48);
    scoreText.setColor(sf::Color::Black);
    scoreText.setString(score);

    if (!lifeScoreTexture.loadFromFile("res/life.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
    lifeScore.setTexture(lifeScoreTexture);
    
    // extract to another class (level)
    level = new Level();
    if (!level->loadFromFile("res/level2.tmx")) {
        std::cout << "Can't load level data" << std::endl;
        return false;
    }

    enemies = level->getObjects("enemy"); // check if necessary

    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Enemy(playerAnimation, enemies[i].rect.left, enemies[i].rect.top, *level));
    }

    enemies = level->getObjects("coin"); // check if necessary

    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Coin(coinAnimation, enemies[i].rect.left, enemies[i].rect.top, *level));
    }

    Object playerObject;
    try {
        playerObject = level->getObject("player");
    }
    catch (std::runtime_error) {
        std::cout << "Incorrect level data" << std::endl;
        return false;
    }
    player = new Player(playerAnimation, playerObject.rect.left, playerObject.rect.top, *level);

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
            entities.push_back(new Bullet(bulletAnimation, player->getRect().left, player->getRect().top + 10, player->getDirection(), *level));
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
    if (!player->isAlive()) {
        stateManager->changeState(GameOverState::getInstance(stateManager, score));
    }

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
                    score += 50;
                }
                else if (!player->isHit()){
                    player->changeHealth(-10); // animation hit
                    player->setHit(true);
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
                score += 20;                
                (*it)->eliminate();
            }
        }
    }
}

void PlayState::onRender(sf::RenderWindow &window)
{
    view.setCenter(player->getRect().left, player->getRect().top);
    window.setView(view);

    level->draw(window);

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        (*it)->draw(window);
    }

    player->draw(window);

    scoreText.setString(std::to_string(score));
    scoreText.setPosition(view.getCenter().x - DEFAULT_WINDOW_WIDTH / 2 + 50, view.getCenter().y - DEFAULT_WINDOW_HEIGHT / 2 + 10);
    window.draw(scoreText);

    for (size_t i = 0; i < player->getHealth() / 10; ++i) {
        lifeScore.setPosition(view.getCenter().x + DEFAULT_WINDOW_WIDTH / 2 - 70 - i * 50, view.getCenter().y - DEFAULT_WINDOW_HEIGHT / 2 + 20);
        window.draw(lifeScore); // TODO transparent texture
    }   
}

void PlayState::onCleanup()
{
    enemies.clear();
    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        delete *it;
    }
    entities.clear();
    delete player;
    delete level;
}

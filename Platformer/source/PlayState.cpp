#include "PlayState.h"
#include "LoadState.h"

bool PlayState::onInit()
{
    player = nullptr;
    level = nullptr;

    view.reset(sf::FloatRect(0, 0, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y));

    if (!backgroundTexture.loadFromFile("res/background_g.jpg")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    if (!playerTexture.loadFromFile("res/aladdin.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    if (!enemyTexture.loadFromFile("res/enemy.png")) {
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

    playerAnimation.loadFromXML("res/aladdin.xml", playerTexture); // check
    enemyAnimation.loadFromXML("res/enemy.xml", enemyTexture);
    bulletAnimation.loadFromXML("res/bullet.xml", bulletTexture);
    coinAnimation.loadFromXML("res/coin.xml", coinTexture);

    background.setTexture(backgroundTexture);
    background.setOrigin(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2);

    if (!font.loadFromFile("res/font.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(48);
    scoreText.setColor(sf::Color::Black);
    //scoreText.setString(score);

    if (!lifeScoreTexture.loadFromFile("res/life.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
    lifeScore.setTexture(lifeScoreTexture);

    loadLevel();

    stateManager->settings.stopMusic(); //tmp

    return true;
}

void PlayState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            levels.assign(levelsPath, levelsPath + LEVELS_QUANTITY);
            score = 0;
            stateManager->changeState(MenuState::getInstance(stateManager));
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
    switch (player->getSound()) {
    case PlayerSounds::JUMP_S:
        player->setSound(PlayerSounds::NONE);
        stateManager->settings.playSound(Sounds::JUMP);
        break;
    case PlayerSounds::HIT_S:
        player->setSound(PlayerSounds::NONE);
        stateManager->settings.playSound(Sounds::DIE);
        break;
    default:
        break;
    }
     
    if (!player->isAlive()) {
        if (player->getHealth() <= 0) {
            levels.assign(levelsPath, levelsPath + LEVELS_QUANTITY);
            stateManager->changeState(GameOverState::getInstance(stateManager, score));
            score = 0;
            return;
        }
        if (levels.size() == 0) {
            levels.assign(levelsPath, levelsPath + LEVELS_QUANTITY);
            stateManager->changeState(GameOverState::getInstance(stateManager, score, true));
            score = 0;
        }
        else {
            stateManager->settings.playSound(Sounds::LEVEL_UP);
            stateManager->changeState(LoadState::getInstance(stateManager, 3, true));
        }
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
                    player->dy = -0.27;
                    enemy->eliminate();
                    score += 50;
                    stateManager->settings.playSound(Sounds::BUMP);
                }
                else if (!player->isHit()){
                    player->changeHealth(-10); // animation hit
                    player->setHit(true);
                    stateManager->settings.playSound(Sounds::DIE);
                   /* if (player->getRect().left > enemy->getRect().left)
                        player->x += 50;
                    else
                        player->x -= 50;*/
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
                stateManager->settings.playSound(Sounds::COIN);
            }
        }
    }
}

void PlayState::onRender(sf::RenderWindow &window)
{ 
    view.setCenter(player->getRect().left, player->getRect().top - stateManager->settings.getResolution().y / 5);
    window.setView(view);

    background.setPosition(view.getCenter());
    window.draw(background);

    level->draw(window);

    for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        (*it)->draw(window);
    }

    player->draw(window);

    scoreText.setString(std::to_string(score));
    scoreText.setPosition(view.getCenter().x - stateManager->settings.getResolution().x / 2 + 50, view.getCenter().y - stateManager->settings.getResolution().y / 2 + 10);
    window.draw(scoreText);

    for (size_t i = 0; i < player->getHealth() / 10; ++i) {
        lifeScore.setPosition(view.getCenter().x + stateManager->settings.getResolution().x / 2 - 70 - i * 50, view.getCenter().y - stateManager->settings.getResolution().y / 2 + 30);
        window.draw(lifeScore); 
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

bool PlayState::loadLevel()
{
    if (levels.size() == 0) {
        return false;
    }
    std::string path = *levels.begin();
    levels.erase(levels.begin());
    
    //if (level != nullptr) {
    //    delete level;
    //}
    level = new Level();
    if (!level->loadFromFile(path)) {
        std::cout << "Can't load level data" << std::endl;
        return false;
    }

    //for each (Entity *entity in entities) {
    //    delete entity;
    //}
    //entities.clear();

    enemies = level->getObjects("enemy"); // check if necessary

    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Enemy(enemyAnimation, enemies[i].rect.left, enemies[i].rect.top, *level));
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
    
    //if (player != nullptr) {
    //    delete player;
    //}
    player = new Player(playerAnimation, playerObject.rect.left, playerObject.rect.top, *level);
    
    return true;
}

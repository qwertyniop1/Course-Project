#include "Application.h"

int Application::onExecute()
{
    if (!onInit()) {
        return -1;
    }

    sf::Clock clock;
    double time;
#if 0
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        
        player->draw(window);
        
        window.display();
    }
#endif
    while (window.isOpen()) {
        sf::Event event;

        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    //entities.push_back(new Bullet(bulletAnimation, player.x, player.y + 10/**/, player.direction));
                }
            }
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

        animationManager.tick(time);

        player->update(time);

        for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ) {
            Entity *bullet = *it;

            if (!bullet->isAlive()) {
                it = entities.erase(it);
                delete bullet;
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
        }

        window.clear(sf::Color::White);

        view.setCenter(player->getRect().left, player->getRect().top);
        window.setView(view);

        level.draw(window);

        for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
            (*it)->draw(window);
        }

        player->draw(window);

        window.display();
    }

    onCleanup();

    return 0;
}

bool Application::onInit()
{
    window.create(sf::VideoMode(600, 400), "Game");  // check
    view.setViewport(sf::FloatRect(0, 0, 600, 400));

    if (!playerTexture.loadFromFile("res/fang.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    animationManager.loadFromXML("res/hero.xml", playerTexture); // check

    if (!bulletTexture.loadFromFile("res/bullet.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
// extract to another class (level)
    if (!level.loadFromFile("res/level2.tmx")) {
        std::cout << "Can't load level data" << std::endl;
        return false;
    }

    enemies = level.getObjects("enemy"); // check if necessary
    
    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Enemy(animationManager, enemies[i].rect.left, enemies[i].rect.top, level));
    }

    Object playerObject;
    try {
        playerObject = level.getObject("player");
    }
    catch (std::runtime_error) {
        std::cout << "Incorrect level data" << std::endl;
        return false;
    }
    //player = new Player(animationManager, playerObject.rect.left, playerObject.rect.top, level);
    player = new Player(animationManager, 50, 50, level);


    return true;
}

void Application::onCleanup()
{
    //entities.clear();
    delete player;
}
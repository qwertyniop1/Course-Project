#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimationManager.h"
#include "Entity.h"
#include "Bullet.h"

#include <list>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 400), "Test");

    View view(FloatRect(0, 0, 600, 400));

    Texture playerTexture;
    playerTexture.loadFromFile("res/fang.png");
        
    AnimationManager animationManager;
    animationManager.loadFromXML("res/hero.xml", playerTexture);

    Texture bulletTexture;
    bulletTexture.loadFromFile("res/bullet.png");

    /*AnimationManager bulletAnimation;
    bulletAnimation.create("move", bulletTexture, 7, 10, 8, 8, 1, 0, 0);
    bulletAnimation.create("explode", bulletTexture, 27, 7, 18, 18, 4, 0.01, 29);*/

    std::list<Entity*> entities;

    Level level;
    level.loadFromFile("res/level2.tmx");

    std::vector<Object> enemies = level.getObjects("enemy");
    for (size_t i = 0; i < enemies.size(); ++i) {
        entities.push_back(new Enemy(animationManager, enemies[i].rect.left, enemies[i].rect.top, level));
    }

    Object playerObject = level.getObject("player");
    Player player(animationManager, playerObject.rect.left, playerObject.rect.top, level);
     
    Clock clock;
    double time;
    
    while (window.isOpen()) {
        Event event;

        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    //entities.push_back(new Bullet(bulletAnimation, player.x, player.y + 10/**/, player.direction));
                }
            }
        }

        
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.keys[Player::Key::Left] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.keys[Player::Key::Right] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player.keys[Player::Key::Up] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            player.keys[Player::Key::Down] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            player.keys[Player::Key::Space] = true;
        }

        animationManager.tick(time);

        player.update(time);

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
                if (player.getRect().intersects(enemy->getRect())) {
                    if (player.dy > 0) {
                        enemy->dx = 0;
                        player.dy = -0.2;
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

        window.clear(Color::White);   

        view.setCenter(player.getRect().left, player.getRect().top);
        window.setView(view);

        level.draw(window);

        for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
            (*it)->draw(window);
        }

        player.draw(window);

        window.display();
    }

    return 0;
}

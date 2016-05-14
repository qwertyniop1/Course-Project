#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimationManager.h"
#include "Bullet.h"

#include <list>

using namespace sf;

RectangleShape tile(Vector2f(32, 32));

double offsetX = 0, offsetY = 0;

int main()
{
    RenderWindow window(VideoMode(600, 400), "Test");

    Texture texture;
    texture.loadFromFile("res/fang.png");

    AnimationManager animationManager;
    animationManager.create("walk", texture, 0, 244, 40, 50, 6, 0.005, 40);
    animationManager.create("jump", texture, 0, 528, 29, 30, 4, 0.005, 38);
    animationManager.create("duck", texture, 0, 436, 80, 20, 1, 0.005, 0);
    animationManager.create("stay", texture, 0, 187, 42, 52, 3, 0.002, 42);
    animationManager.create("shoot", texture, 0, 572, 45, 52, 5, 0.005, 45);

    Texture bulletTexture;
    bulletTexture.loadFromFile("res/bullet.png");

    AnimationManager bulletAnimation;
    bulletAnimation.create("move", bulletTexture, 7, 10, 8, 8, 1, 0, 0);
    bulletAnimation.create("explode", bulletTexture, 27, 7, 18, 18, 4, 0.01, 29);
   
    Player player(animationManager);
    
    std::list<Bullet*> bullets;
     
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
                    bullets.push_back(new Bullet(bulletAnimation, player.rect.left, player.rect.top, player.direction));
                }
            }
        }

        animationManager.set("stay");

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

        for (std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ) {
            Bullet *bullet = *it;

            if (!bullet->isAlive) {
                it = bullets.erase(it);
                delete bullet;
            }
            else {
                it++;
            }
        }

        for (std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
            (*it)->update(time);
        }

        /*if (player.rect.intersects(enemy.rect)) {
            if (enemy.isAlive) {
                if (player.dy > 0) {
                    enemy.dx = 0;
                    enemy.isAlive = false;
                    player.dy = -0.2;
                }
                else {
                    player.sprite.setColor(Color::Red);
                }
            }
        }*/

        if (player.rect.left > 300) {
            offsetX = player.rect.left - 300;
        }
        if (player.rect.top < 200) {
            offsetY = player.rect.top - 200;
        }
        
        window.clear(Color::White);

        for (size_t i = 0; i < HEIGHT; ++i) {
            for (size_t j = 0; j < WIDTH; ++j) {
                if (tileMap[i][j] == 'B') {
                    tile.setFillColor(Color::Black);
                }
                if (tileMap[i][j] == '0') {
                    tile.setFillColor(Color::Green);
                }
                if (tileMap[i][j] == ' ') {
                    continue;
                }

                tile.setPosition(j * 32 - offsetX, i * 32 - offsetY);
                window.draw(tile);
            }
        }

        for (std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
            (*it)->draw(window);
        }

        player.draw(window);

        window.display();
    }

    return 0;
}

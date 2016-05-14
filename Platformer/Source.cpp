#include "Global.h"
#include "Player.h"
#include "Enemy.h"

using namespace sf;

RectangleShape tile(Vector2f(32, 32));

double offsetX = 0, offsetY = 0;

int main()
{
    RenderWindow window(VideoMode(600, 400), "Test");

    Texture texture;
    texture.loadFromFile("res/fang.png");

    Player player(texture);
    Enemy enemy(texture, 32 * 27, 302);

    Clock clock;
    double time;

    double currentFrame = 0;
    
    while (window.isOpen()) {
        Event event;

        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.dx = -0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.dx = 0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (player.onSurface) {
                player.dy = -0.4;
                player.onSurface = false;
            }
        }

        player.update(time);
        enemy.update(time);

        if (player.rect.intersects(enemy.rect)) {
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
        }

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
        window.draw(player.sprite);
        window.draw(enemy.sprite);

        window.display();
    }

    return 0;
}

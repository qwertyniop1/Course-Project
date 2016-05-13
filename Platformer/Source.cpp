#include <SFML\Graphics.hpp>
#include "Player.h"

using namespace sf;

const int HEIGHT = 12;
const int WIDTH = 40;
String tileMap[HEIGHT] = {

    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B         0000                BBBB     B",
    "B                                B     B",
    "BBB                              B     B",
    "B              BB                BB    B",
    "B              BB                      B",
    "B    B         BB         BB           B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};
RectangleShape tile(Vector2f(32, 32));

int main()
{
    RenderWindow window(VideoMode(600, 400), "Test");

    Texture texture;
    texture.loadFromFile("res/fang.png");

    Player player(texture);

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

                tile.setPosition(j * 32, i * 32);
                window.draw(tile);
            }
        }
        window.draw(player.sprite);

        window.display();
    }


    return 0;
}
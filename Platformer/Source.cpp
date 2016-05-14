#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 100;

int main()
{
    char str[N];
    fgets(str, N, stdin);

    int length = strlen(str);
    int a = sqrt(length);

    char **matrix = (char**)malloc(a * sizeof(char*));
    if (matrix == NULL) {
        printf("Memory error");
        exit(1);
    }

    int i, j;
    for (i = 0; i < a; i++) {
        matrix[i] = (char*)malloc(a * sizeof(char));
        if (matrix[i] == NULL) {
            printf("Memory error");
            exit(1);
        }
    }
      
    i = 0;
        int k, p = a / 2;
    for (k = 1; k <= p; k++)/*Цикл по номеру витка*/
    {  
       
        for (j = a - k - 1; j >= k; j++)
            matrix[j][k - 1] = str[i++];/* --//-- по левому вертикальному столбцу*/
        for (j = a - k - 1; j >= k - 1; ++j)
            matrix[a - k][j] = str[i++];/* --//-- по нижнему горизонтальному столбцу*/
        for (j = k; j<a - k + 1; j--)
            matrix[j][a - k] = str[i++];/* --//-- По правому вертикальному столбцу*/
        for (j = k - 1; j<a - k + 1; j--)
            matrix[k - 1][j] = str[i++];/*Определение значений верхнего горизонтального столбца*/
    }
    if (a % 2 == 1)
        matrix[p][p] = a * a;
    for (i = 0; i<a; i++)
        for (j = 0; j<a; j++)
        {
            printf(" %4c ", matrix[i][j]);
            if (j == a - 1)
                printf("\n");
        }

    getchar();
    return 0;
}

double offsetX = 0, offsetY = 0;
#if 0
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
    Enemy enemy(texture, 32 * 27, 32 * 10 - 20);

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
#endif
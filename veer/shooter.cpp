
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 15;

int playerX = WIDTH / 2;
int score = 0;
bool gameOver = false;

struct Enemy {
    int x, y;
};

vector<Enemy> enemies;
vector<Enemy> bullets;

void draw() {
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << '\n';

    for (int y = 0; y < HEIGHT; y++) {
        cout << "#";

        for (int x = 0; x < WIDTH; x++) {
            bool printed = false;

            if (y == HEIGHT - 1 && x == playerX) {
                cout << "A";
                printed = true;
            }

            for (auto e : enemies) {
                if (e.x == x && e.y == y) {
                    cout << "V";
                    printed = true;
                    break;
                }
            }

            if (!printed) {
                for (auto b : bullets) {
                    if (b.x == x && b.y == y) {
                        cout << "|";
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed)
                cout << " ";
        }

        cout << "#\n";
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";

    cout << "\nScore: " << score;
    cout << "\nA: Left | D: Right | Space: Shoot | Q: Quit\n";
}

void input() {
    if (!_kbhit())
        return;

    char key = _getch();

    if (key == 'a' || key == 'A') {
        if (playerX > 0)
            playerX--;
    }
    else if (key == 'd' || key == 'D') {
        if (playerX < WIDTH - 1)
            playerX++;
    }
    else if (key == ' ') {
        bullets.push_back({playerX, HEIGHT - 2});
    }
    else if (key == 'q' || key == 'Q') {
        gameOver = true;
    }
}

void update() {
    // Move bullets upward
    for (int i = 0; i < (int)bullets.size(); i++)
        bullets[i].y--;

    // Remove bullets that leave the screen
    for (int i = 0; i < (int)bullets.size();) {
        if (bullets[i].y < 0)
            bullets.erase(bullets.begin() + i);
        else
            i++;
    }

    // Spawn enemies randomly
    if (rand() % 5 == 0)
        enemies.push_back({rand() % WIDTH, 0});

    // Move enemies downward
    for (auto &e : enemies)
        e.y++;

    // Detect bullet-enemy collisions
    for (int i = 0; i < (int)enemies.size();) {
        bool destroyed = false;

        for (int j = 0; j < (int)bullets.size(); j++) {
            if (enemies[i].x == bullets[j].x &&
                enemies[i].y == bullets[j].y) {

                enemies.erase(enemies.begin() + i);
                bullets.erase(bullets.begin() + j);

                score += 10;
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            i++;
    }

    // Check if an enemy reaches the player
    for (auto e : enemies) {
        if (e.y >= HEIGHT - 1 && e.x == playerX) {
            gameOver = true;
            break;
        }

        if (e.y >= HEIGHT)
            gameOver = true;
    }
}

int main() {
    srand((unsigned)time(0));

    cout << "=== C++ SHOOTER GAME ===\n";
    cout << "Press any key to start...\n";
    _getch();

    while (!gameOver) {
        input();
        update();
        draw();
        Sleep(120);
    }

    cout << "\n\nGAME OVER!\n";
    cout << "Final Score: " << score << '\n';

    system("pause");
    return 0;
}

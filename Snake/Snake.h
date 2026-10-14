#ifndef SNAKE_H
#define SNAKE_H

#include "../Game.h"

struct Node
{
    int x;
    int y;
    Node* next;
};

class Snake : public Game
{
private:
    Node* head;

    int foodX;
    int foodY;
    int score;
    char direction;

    static const int WIDTH = 30;
    static const int HEIGHT = 15;

    void createSnake();
    void addSegment(int x, int y);
    void generateFood();
    bool isFoodOnSnake();
    bool checkSelfCollision(int x, int y);
    void drawBoard();
    void moveSnake();

public:
    Snake();

    void run() override;
};

#endif
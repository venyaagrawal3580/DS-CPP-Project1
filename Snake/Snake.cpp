#include "Snake.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;


// Constructor
Snake::Snake()
{
    head = nullptr;
    foodX = 0;
    foodY = 0;
    score = 0;
    direction = 'd';
}


// Create the initial Snake
void Snake::createSnake()
{
    head = new Node;

    head->x = 5;
    head->y = 5;
    head->next = nullptr;

    addSegment(4, 5);
    addSegment(3, 5);
    addSegment(2, 5);
}


// Add a new segment
void Snake::addSegment(int x, int y)
{
    Node* newNode = new Node;

    newNode->x = x;
    newNode->y = y;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Generate food
void Snake::generateFood()
{
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}


// Check if food is on the Snake
bool Snake::isFoodOnSnake()
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->x == foodX && temp->y == foodY)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}


// Draw the Snake UI
void Snake::drawBoard()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD position;
    position.X = 0;
    position.Y = 0;

    SetConsoleCursorPosition(hConsole, position);

    cout << "========================================" << endl;
    cout << "               S N A K E                " << endl;
    cout << "========================================" << endl;

    cout << "Score: " << score << "                    " << endl;
    cout << endl;

    cout << "+";

    for (int x = 0; x < WIDTH; x++)
    {
        cout << "-";
    }

    cout << "+" << endl;


    for (int y = 0; y < HEIGHT; y++)
    {
        cout << "|";

        for (int x = 0; x < WIDTH; x++)
        {
            bool printed = false;

            Node* temp = head;

            while (temp != nullptr)
            {
                if (temp->x == x && temp->y == y)
                {
                    if (temp == head)
                    {
                        cout << "O";
                    }
                    else
                    {
                        cout << "o";
                    }

                    printed = true;
                    break;
                }

                temp = temp->next;
            }

            if (!printed)
            {
                if (foodX == x && foodY == y)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }

        cout << "|" << endl;
    }


    cout << "+";

    for (int x = 0; x < WIDTH; x++)
    {
        cout << "-";
    }

    cout << "+" << endl;

    cout << endl;
    cout << "Controls: W A S D" << endl;
    cout << "Press X to return to menu.        " << endl;
}


// Check self collision
bool Snake::checkSelfCollision(int x, int y)
{
    Node* temp = head->next;

    while (temp != nullptr)
    {
        if (temp->x == x && temp->y == y)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}


// Move the Snake
void Snake::moveSnake()
{
    int newX = head->x;
    int newY = head->y;


    if (direction == 'w')
    {
        newY--;
    }
    else if (direction == 's')
    {
        newY++;
    }
    else if (direction == 'a')
    {
        newX--;
    }
    else if (direction == 'd')
    {
        newX++;
    }


    // Wall collision
    if (newX < 0 || newX >= WIDTH ||
        newY < 0 || newY >= HEIGHT)
    {
        cout << "\nGame Over! You hit the wall.\n";
        Sleep(1500);
        return;
    }


    // Self collision
    if (checkSelfCollision(newX, newY))
    {
        cout << "\nGame Over! You hit yourself.\n";
        Sleep(1500);
        return;
    }


    // Create new head
    Node* newHead = new Node;

    newHead->x = newX;
    newHead->y = newY;
    newHead->next = head;

    head = newHead;


    // Food eaten
    if (head->x == foodX && head->y == foodY)
    {
        score += 10;

        do
        {
            generateFood();
        }
        while (isFoodOnSnake());
    }
    else
    {
        // Remove tail
        Node* temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = nullptr;
    }
}


// Run the Snake game
void Snake::run()
{
    srand(static_cast<unsigned int>(time(0)));

    system("cls");

    createSnake();
    generateFood();

    while (true)
    {
        drawBoard();


        if (_kbhit())
        {
            char key = _getch();


            if (key == 'x' || key == 'X')
            {
                break;
            }


            if (key == 'w' && direction != 's')
            {
                direction = 'w';
            }
            else if (key == 's' && direction != 'w')
            {
                direction = 's';
            }
            else if (key == 'a' && direction != 'd')
            {
                direction = 'a';
            }
            else if (key == 'd' && direction != 'a')
            {
                direction = 'd';
            }
        }


        moveSnake();

        Sleep(150);
    }


    system("cls");
}
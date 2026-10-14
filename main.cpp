#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Snake/Snake.h"

using namespace std;


// Display the main menu
void displayMenu()
{
    cout << "========================================" << endl;
    cout << "               PLAYABLE                 " << endl;
    cout << "       Interactive Game Platform        " << endl;
    cout << "========================================" << endl;

    cout << endl;

    cout << "                MENU                    " << endl;
    cout << "----------------------------------------" << endl;

    cout << "   1. Snake" << endl;
    cout << "   2. Sudoku" << endl;
    cout << "   3. Minesweeper" << endl;
    cout << "   4. Tic-Tac-Toe" << endl;
    cout << "   5. Exit" << endl;

    cout << "----------------------------------------" << endl;
    cout << "Enter your choice: ";
}


int main()
{
    Snake snake;

    int choice;

    while (true)
    {
        system("cls");

        displayMenu();

        cin >> choice;

        system("cls");


        if (choice == 1)
        {
            Game* game = &snake;

            game->run();
        }
        else if (choice == 2)
        {
            cout << "Sudoku module coming soon..." << endl;
            system("pause");
        }
        else if (choice == 3)
        {
            cout << "Minesweeper module coming soon..." << endl;
            system("pause");
        }
        else if (choice == 4)
        {
            cout << "Tic-Tac-Toe module coming soon..." << endl;
            system("pause");
        }
        else if (choice == 5)
        {
            cout << "Thank you for playing PLAYABLE!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            system("pause");
        }
    }

    return 0;
}
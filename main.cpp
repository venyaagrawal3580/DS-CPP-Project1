
#include <iostream>
#include <limits>
#include <cstdlib>

#include "Game.h"
#include "Snake/Snake.h"

using namespace std;

// Display the main menu
void displayMenu()
{
    cout << "========================================\n";
    cout << "              PLAYABLE\n";
    cout << "       Interactive Game Platform\n";
    cout << "========================================\n\n";

    cout << "  Select a game to play:\n\n";
    cout << "  1. Snake\n";
    cout << "  2. Sudoku          [Coming Soon]\n";
    cout << "  3. Minesweeper     [Coming Soon]\n";
    cout << "  4. Tic-Tac-Toe     [Coming Soon]\n";
    cout << "  5. Exit\n\n";

    cout << "----------------------------------------\n";
    cout << "Enter your choice (1-5): ";
}

int main()
{
    Snake snake;
    int choice;

    while (true)
    {
        system("cls");
        displayMenu();

        // Validate user input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            cout << "\nInvalid input! Please enter a number.\n";
            system("pause");
            continue;
        }

        system("cls");

        switch (choice)
        {
            case 1:
            {
                Game* game = &snake;
                game->run();
                break;
            }

            case 2:
                cout << "Sudoku is coming soon!\n";
                cout << "Stay tuned for future updates.\n";
                system("pause");
                break;

            case 3:
                cout << "Minesweeper is coming soon!\n";
                system("pause");
                break;

            case 4:
                cout << "Tic-Tac-Toe is coming soon!\n";
                system("pause");
                break;

            case 5:
                cout << "Thanks for playing PLAYABLE!\n";
                cout << "Keep exploring and have fun!\n";
                return 0;

            default:
                cout << "Invalid choice! Select a number from 1 to 5.\n";
                system("pause");
        }
    }

    return 0;
}

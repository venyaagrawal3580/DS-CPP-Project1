#include "TicTacToe.h"

#include <iostream>
#include <limits>

using namespace std;

TicTacToe::TicTacToe()
{
    initBoard();
}

void TicTacToe::initBoard()
{
    char c = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = c++;
        }
    }
}

void TicTacToe::printBoard()
{
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0]
             << " | " << board[i][1]
             << " | " << board[i][2] << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool TicTacToe::placeMove(int pos, char player)
{
    if (pos < 1 || pos > 9)
        return false;

    int r = (pos - 1) / 3;
    int c = (pos - 1) % 3;

    if (board[r][c] == 'X' || board[r][c] == 'O')
        return false;

    board[r][c] = player;
    return true;
}

bool TicTacToe::checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

void TicTacToe::run()
{
    initBoard();

    char player = 'X';
    int moves = 0;
    int pos;

    cout << "=== TIC TAC TOE ===\n";
    cout << "Player 1: X | Player 2: O\n";

    while (true)
    {
        printBoard();

        cout << "Player " << player
             << ", enter position (1-9): ";

        if (!(cin >> pos))
        {
            if (cin.eof())
                return;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number from 1 to 9.\n";
            continue;
        }

        if (!placeMove(pos, player))
        {
            cout << "Invalid or taken position. Try again.\n";
            continue;
        }

        moves++;

        if (checkWin(player))
        {
            printBoard();
            cout << "Player " << player << " wins!\n";
            return;
        }

        if (moves == 9)
        {
            printBoard();
            cout << "It's a draw!\n";
            return;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
}

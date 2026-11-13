#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../Game.h"

class TicTacToe : public Game
{
private:
    char board[3][3];

    void initBoard();
    void printBoard();
    bool placeMove(int pos, char player);
    bool checkWin(char player);

public:
    TicTacToe();
    void run() override;
};

#endif

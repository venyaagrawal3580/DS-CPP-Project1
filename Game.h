
#ifndef GAME_H
#define GAME_H

class Game
{
public:
    // Virtual destructor for safe polymorphic use
    virtual ~Game() = default;

    // Common interface for all games
    virtual void run() = 0;
};

#endif

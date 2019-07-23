#ifndef _GAME_H
#define _GAME_H

#include "player.h"

class Game {
    Player human;
    Player computer;
    public:
        Game();
        ~Game();
        void displayWinner();
        bool isCheck();
        bool isCheckmate();
        bool isStalemate();
};

#endif _GAME_H
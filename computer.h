#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "player.h"

class Computer: public Player {
    int level;
    public:
        Computer(int level);
        ~Computer();
        void undo() override;
};

#endif _COMPUTER_H
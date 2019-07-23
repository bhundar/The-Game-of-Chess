#ifndef _HUMAN_H
#define _HUMAN_H

#include "player.h"

class Human: public Player {
    public:
        Human();
        ~Human();
        void undo() override;
};

#endif _HUMAN_H
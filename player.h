#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>

class Player {
    int numWins;
    //std::vector < std::vector < std::string, std::string, std::string > > moves;
    public:
        Player();
        ~Player();
        virtual void undo();
};

#endif _PLAYER_H

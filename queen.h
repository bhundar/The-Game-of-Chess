#ifndef _QUEEN_H
#define _QUEEN_H

#include "piece.h"

class Queen: public Piece {
    public:
        Queen(Colour colour, PieceType type);
        ~Queen();
};

#endif _QUEEN_H
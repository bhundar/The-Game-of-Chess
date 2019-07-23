#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "piece.h"

class Knight: public Piece {
    public:
        Knight(Colour colour, PieceType type);
        ~Knight();
};

#endif _KNIGHT_H
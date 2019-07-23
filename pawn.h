#ifndef _PAWN_H
#define _PAWN_H

#include "piece.h"

class Pawn: public Piece {
    public:
        Pawn(Colour colour, PieceType type);
        ~Pawn();
};

#endif _PAWN_H
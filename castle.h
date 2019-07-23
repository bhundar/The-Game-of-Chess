#ifndef _CASTLE_H
#define _CASTLE_H

#include "piece.h"

class Castle: public Piece {
    public:
        Castle(Colour colour, PieceType type);
        ~Castle();
};

#endif _CASTLE_H
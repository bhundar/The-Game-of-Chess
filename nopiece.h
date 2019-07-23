#ifndef _NOPIECE_H
#define _NOPIECE_H

#include "piece.h"

class NoPiece: public Piece {
    public:
        NoPiece(Colour colour, PieceType type);
        ~NoPiece();
};

#endif _NOPIECE_H
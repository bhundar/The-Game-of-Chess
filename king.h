#ifndef _KING_H
#define _KING_H

#include "piece.h"

class King: public Piece {
    public:
        King(Colour colour, PieceType type);
        ~King();
};

#endif _KING_H
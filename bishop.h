#ifndef _BISHOP_H
#define _BISHOP_H

#include "piece.h"
#include "piece.h"

class Bishop: public Piece {
    public:
        Bishop(Colour colour, PieceType type);
        ~Bishop();
};

#endif _BISHOP_H
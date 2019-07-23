#ifndef _TILE_H
#define _TILE_H

//#include "piece.h"
#include "info.h"
#include "piece.h"

class Tile {
    Piece * piece;
    int alphabet;
    int num;
    Colour c;
    PieceType p;
    public:
        Tile();
        Tile(int alphabet, int number, Colour colour, PieceType pieceType);
        ~Tile();
        void placePiece(Piece * piece);
        Info getInfo() const;

};

#endif _TILE_H
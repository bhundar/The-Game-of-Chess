#ifndef _TILE_H
#define _TILE_H

#include "info.h"
#include "piece.h"
#include "game.h"


class Tile {
    Piece * piece;
    public:
        Colour c;
        PieceType p;
        int alphabet;
        int num;
        Tile();
        Tile(int alphabet, int number, Colour colour, PieceType pieceType);
        ~Tile();
        void placePiece(Piece * piece);
        Info getInfo() const;

};

#endif _TILE_H
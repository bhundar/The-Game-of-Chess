#ifndef _INFO_H
#define _INFO_H
#include <iostream>
#include <cstddef>

enum class PieceType { Castle, Pawn, Knight, Bishop, Queen, King, NoPiece };
enum class Colour { White, Black, NoColour };

struct Info {
    int alp;
    int num;
    PieceType type;
    Colour colour;
};

#endif _INFO_H
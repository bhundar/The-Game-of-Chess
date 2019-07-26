#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include "game.h"
#include "piece.h"
#include "tile.h"
#include "info.h"
#include <vector>
#include <cstdlib>

class ChessBoard: public Game {
    const int boardSize = 8;
    public:
        std::vector<std::vector<Tile>> chessBoard;
        ChessBoard();
        ~ChessBoard();
        void init_empty();
        void init();
        friend std::ostream &operator<<(std::ostream &out, const ChessBoard &cb);
};

bool IsLegal(Tile t1, Tile t2);
bool IsValid(Tile t1, Tile t2, ChessBoard &cb);

#endif _CHESSBOARD_H






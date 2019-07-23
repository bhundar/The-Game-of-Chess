#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include "game.h"
#include "piece.h"
#include "tile.h"
#include "info.h"
#include <vector>

class ChessBoard: public Game {
    const int boardSize = 8;
    std::vector<std::vector<Tile>> chessBoard;
    public:
        ChessBoard();
        ~ChessBoard();
        void init();
        friend std::ostream &operator<<(std::ostream &out, const ChessBoard &cb);
};

#endif _CHESSBOARD_H






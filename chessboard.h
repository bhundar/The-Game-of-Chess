#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#include "game.h"
#include "piece.h"
#include "tile.h"
#include "info.h"
//#include "graphicsdisplay.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

class ChessBoard: public Game {
    const int boardSize = 8;
    //GraphicsDisplay * gd;
    public:
        bool hasPawnMovedTwice = false;
        bool castlingWhiteAllowedRight = true;
        bool castlingWhiteAllowedLeft = true;
        bool castlingBlackAllowedRight = true;
        bool castlingBlackAllowedLeft = true;
        int WhiteKingPosX(ChessBoard &cb);
        int WhiteKingPosY(ChessBoard &cb);
        int BlackKingPosX(ChessBoard &cb);
        int BlackKingPosY(ChessBoard &cb);
        int getX(char s);
        int getY(char s);
        std::vector<std::vector<Tile>> chessBoard;
        ChessBoard();
        ~ChessBoard();
        bool isWhiteCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector);
        bool isBlackCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector);
        //bool isWhiteCheck(ChessBoard &cb, Tile t1, Tile t2, std::vector <std::string> inputVector);
        void init_empty();
        void init();
        friend std::ostream &operator<<(std::ostream &out, const ChessBoard &cb);
};

bool IsLegal(Tile t1, Tile t2, ChessBoard &cb);
bool IsValid(Tile t1, Tile t2, ChessBoard &cb);

#endif _CHESSBOARD_H






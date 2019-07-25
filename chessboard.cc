#include "chessboard.h"
#include "tile.h"
#include "pawn.h"
#include "castle.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "nopiece.h"

ChessBoard::ChessBoard() {

}

ChessBoard::~ChessBoard() {

}

void ChessBoard::init_empty() {
    // Create board 
    for (int height = 0; height < boardSize; ++height) {
        std::vector<Tile> temptile;
        for (int width = 0; width < boardSize; ++width) {
            Tile newTile = {width, height, Colour::NoColour, PieceType::NoPiece};
            temptile.emplace_back(newTile);
            } 
        chessBoard.emplace_back(temptile);
    }
}

void ChessBoard::init() {
    // Create board 
    for (int height = 0; height < boardSize; ++height) {
        std::vector<Tile> temptile;
        for (int width = 0; width < boardSize; ++width) {
            if (1 < height && height < 6) {
                Tile newTile = {width, height, Colour::NoColour, PieceType::NoPiece};
                temptile.emplace_back(newTile);
            } else if (height == 1) {
                Tile newTile = {width, height, Colour::Black, PieceType::Pawn};
                temptile.emplace_back(newTile);
            } else if (height == 6) {
                Tile newTile = {width, height, Colour::White, PieceType::Pawn};
                temptile.emplace_back(newTile);
            } else if (height == 0){
                if (width == 0 || width == 7) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Castle};
                    temptile.emplace_back(newTile);
                } else if (width == 1 || width == 6) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Knight};
                    temptile.emplace_back(newTile);
                }  else  if (width == 2 || width == 5) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Bishop};
                    temptile.emplace_back(newTile);
                } else  if (width == 3) {
                    Tile newTile = {width, height, Colour::Black, PieceType::Queen};
                    temptile.emplace_back(newTile);
                } else  if (width == 4) {
                    Tile newTile = {width, height, Colour::Black, PieceType::King};
                    temptile.emplace_back(newTile);
                } 
            } else if (height == 7) {
                if (width == 0 || width == 7) {
                    Tile newTile = {width, height, Colour::White, PieceType::Castle};
                    temptile.emplace_back(newTile);
                } else  if (width == 1 || width == 6) {
                    Tile newTile = {width, height, Colour::White, PieceType::Knight};
                    temptile.emplace_back(newTile);
                } else  if (width == 2 || width == 5) {
                    Tile newTile = {width, height, Colour::White, PieceType::Bishop};
                    temptile.emplace_back(newTile);
                } else  if (width == 3) {
                    Tile newTile = {width, height, Colour::White, PieceType::Queen};
                    temptile.emplace_back(newTile);
                } else  if (width == 4) {
                    Tile newTile = {width, height, Colour::White, PieceType::King};
                    temptile.emplace_back(newTile);
                } 
            }
        }
        chessBoard.emplace_back(temptile);
    }
}

std::ostream &operator<<(std::ostream &out, const ChessBoard &cb) {
    for (int height = 0; height < 9; ++height) {
        for (int width = 0; width < 8; ++width) {
            // printing numbers left
            if (height == 0 && width == 0) {
                out << "8 ";
            } else if (height == 1 && width == 0) {
                out << "7 ";
            } else if (height == 2 && width == 0) {
                out << "6 ";
            } else if (height == 3 && width == 0) {
                out << "5 ";
            } else if (height == 4 && width == 0) {
                out << "4 ";
            } else if (height == 5 && width == 0) {
                out << "3 ";
            } else if (height == 6 && width == 0) {
                out << "2 ";
            } else if (height == 7 && width == 0) {
                out << "1 ";
            }
            // printing alphabets bottom
            if (height == 8 && width == 0) {
                out << "  a";
            } else if (height == 8 && width == 1) {
                out << "b";
            } else if (height == 8 && width == 2) {
                out << "c";
            } else if (height == 8 && width == 3) {
                out << "d";
            } else if (height == 8 && width == 4) {
                out << "e";
            } else if (height == 8 && width == 5) {
                out << "f";
            } else if (height == 8 && width == 6) {
                out << "g";
            } else if (height == 8 && width == 7) {
                out << "h";
            }
            // printing chess pieces
            if (height < 8) {
                if (cb.chessBoard[height][width].getInfo().colour == Colour::White) {
                if (cb.chessBoard[height][width].getInfo().type == PieceType::Pawn) {
                    out << "P";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Castle) {
                    if (height == 7 && width == 7) {
                        out << "R";
                        std::cout << std::endl;
                    } else {
                        out << "R";
                    }
                    
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Knight) {
                    out << "N";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Bishop) {
                    out << "B";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::King) {
                    out << "K";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Queen) {
                    out << "Q";
                } 
            } else if (cb.chessBoard[height][width].getInfo().colour == Colour::Black) {
                if (cb.chessBoard[height][width].getInfo().type == PieceType::Pawn) {
                    out << "p";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Castle) {
                    out << "r";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Knight) {
                    out << "n";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Bishop) {
                    out << "b";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::King) {
                    out << "k";
                } else if (cb.chessBoard[height][width].getInfo().type == PieceType::Queen) {
                    out << "q";
                }  
            } else {
                out << "-";
            }
            }
        }
        std::cout << std::endl;
    }
    return out;
}
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include "human.h"
#include "computer.h"
#include "chessboard.h"

using namespace std;

PieceType whichPiece(string s) {
    if (s == "K") {
        return PieceType::King;
    } else if (s == "Q") {
        return PieceType::Queen;
    } else if (s == "P") {
        return PieceType::Pawn;
    } else if (s == "R") {
        return PieceType::Castle;
    } else if (s == "N") {
        return PieceType::Knight;
    } else if (s == "B") {
        return PieceType::Bishop;
    } else if (s == "k") {
        return PieceType::King;
    } else if (s == "q") {
        return PieceType::Queen;
    } else if (s == "p") {
        return PieceType::Pawn;
    } else if (s == "r") {
        return PieceType::Castle;
    } else if (s == "n") {
        return PieceType::Knight;
    } else if (s == "b") {
        return PieceType::Bishop;
    } else {
        return PieceType::NoPiece;
    }
}

Colour whichColour(string s) {
    if (s == "K") {
        return Colour::White;
    } else if (s == "Q") {
        return Colour::White;
    } else if (s == "P") {
        return Colour::White;
    } else if (s == "R") {
        return Colour::White;
    } else if (s == "N") {
        return Colour::White;
    } else if (s == "B") {
        return Colour::White;
    } else if (s == "k") {
        return Colour::Black;
    } else if (s == "q") {
        return Colour::Black;
    } else if (s == "p") {
        return Colour::Black;
    } else if (s == "r") {
        return Colour::Black;
    } else if (s == "n") {
        return Colour::Black;
    } else if (s == "b") {
        return Colour::Black;
    } else {
        return Colour::NoColour;
    }
}

Colour whichTurn(int alphabet, int num, ChessBoard &cb) {
    if (cb.chessBoard[8-num][alphabet-1].c == Colour::White) {
        return Colour::White;
    }
    return Colour::Black;
}

string isCastling(string s1, string s2, ChessBoard &cb) {
    if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 1 && cb.getX(s2[0]) == 7 && cb.getY(s2[1]) == 1) { // White right
        if (cb.castlingWhiteAllowedRight) {
                return "wr";
        }
        return "no";   
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 1 && cb.getX(s2[0]) == 3 && cb.getY(s2[1]) == 1) { // White left
        if (cb.castlingWhiteAllowedLeft) {
            return "wl";
        }
        return "no";
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 8 && cb.getX(s2[0]) == 7 && cb.getY(s2[1]) == 8) { // Black right
        if (cb.castlingBlackAllowedRight) {
            return "br";
        }
        return "no";
    } else if (cb.getX(s1[0]) == 5 && cb.getY(s1[1]) == 8 && cb.getX(s2[0]) == 3 && cb.getY(s2[1]) == 8) { // Black left
        if (cb.castlingBlackAllowedLeft) {
            return "bl";
        }
        return "no";
    } else {
        return "no";
    }
}

bool isCastlingLegal(string s, ChessBoard &cb) {
    if (s == "wr") {
        if (cb.chessBoard[7][4].p == PieceType::King && cb.chessBoard[7][4].c == Colour::White &&
            cb.chessBoard[7][5].p == PieceType::NoPiece && cb.chessBoard[7][6].p == PieceType::NoPiece &&
            cb.chessBoard[7][7].p == PieceType::Castle && cb.chessBoard[7][7].c == Colour::White) {
                return true;
            }
            return false;
    } else if (s == "wl") {
        if (cb.chessBoard[7][4].p == PieceType::King && cb.chessBoard[7][4].c == Colour::White &&
            cb.chessBoard[7][3].p == PieceType::NoPiece && cb.chessBoard[7][2].p == PieceType::NoPiece && cb.chessBoard[7][1].p == PieceType::NoPiece &&
            cb.chessBoard[7][0].p == PieceType::Castle && cb.chessBoard[7][0].c == Colour::White) {
                return true;
            }
            return false;
    } else if (s == "br") {
        if (cb.chessBoard[0][4].p == PieceType::King && cb.chessBoard[0][4].c == Colour::Black &&
            cb.chessBoard[0][5].p == PieceType::NoPiece && cb.chessBoard[0][6].p == PieceType::NoPiece &&
            cb.chessBoard[0][7].p == PieceType::Castle && cb.chessBoard[0][7].c == Colour::Black) {
                return true;
            }
            return false;
    } else if (s == "bl") {
        if (cb.chessBoard[0][4].p == PieceType::King && cb.chessBoard[0][4].c == Colour::Black &&
            cb.chessBoard[0][3].p == PieceType::NoPiece && cb.chessBoard[0][2].p == PieceType::NoPiece && cb.chessBoard[7][1].p == PieceType::NoPiece &&
            cb.chessBoard[0][0].p == PieceType::Castle && cb.chessBoard[0][0].c == Colour::Black) {
                return true;
            }
            return false;
    } else {
        return false;
    }
}

Computer * computerInitialization(int computer) {
    if (computer == 1) {
        return new Computer(1);
    } else if (computer == 2) {
        return new Computer(2);
    } else if (computer == 3) {
        return new Computer(3);
    } if (computer == 4) {
        return new Computer(4);
    }
}

int main(void) {
    bool isWhiteTurn = true;
    string input;
    vector <string> inputVector; 
    ChessBoard cb;
    bool invalidSetup = false;
    bool allClear = true;
    int whiteKing = 0;
    int blackKing = 0;
    cout << "==============================" << endl;
    cout << "Hi! Welcome to the Game of Chess" << endl;
    cout << "Type 'game a b' where 'a' is player 1 (W) and b is player 2 (B)" << endl;
    cout << "Player 'a' or 'b' can either be 'human' or 'computer[1-4]'" << endl;
    cout << "To make a move type 'move x y' where 'x' is the current position and 'y' is the new position" << endl;
    cout << "To enter setup mode, type 'setup'" << endl;
    cout << "To leave a game, type 'resign'" << endl;
    cout << "==============================" << endl;
    while (true) {
        getline(cin, input);
        istringstream ss(input);
        string word;
        while (ss >> word) {
            inputVector.emplace_back(word);
        }
        if ((inputVector.size() == 1 || inputVector.size() == 4) && inputVector[0] != "move") {
            if (inputVector[0] == "resign") {
                break;
            } else if (inputVector[0] == "setup") {
                cb.init_empty();
                while (true) {
                    getline(cin, input);
                    istringstream ss(input);
                    string word;
                    while (ss >> word) {
                    inputVector.emplace_back(word);
                    }
                    if (inputVector.size() == 4) {
                        if (inputVector[1] == "+") {
                            PieceType p = whichPiece(inputVector[2]);
                            Colour c = whichColour(inputVector[2]);
                            if (p == PieceType::King && c == Colour::Black) {
                                blackKing += 1;
                            } else if (p == PieceType::King && c == Colour::White) {
                                whiteKing += 1;
                            } 
                            if (p == PieceType::NoPiece || c == Colour::NoColour) {
                                cout << "Invalid input! Please enter command again!" << endl;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            }
                            int x = cb.getX(inputVector[3][0]);
                            int y = cb.getY(inputVector[3][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y && j == x - 1) {
                                        Tile newTile = {i, j, c, p};
                                        cb.chessBoard[i][j] = newTile;
                                        cout << cb;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        continue;
                                    }
                                }
                            }
                        } else {
                            cout << "Invalid input! Please enter command again!" << endl;
                            inputVector.clear();
                            inputVector.emplace_back("setup");
                            continue;
                        }
                    } else if (inputVector.size() == 3) {
                        if (inputVector[1] == "-") {
                            int x1 = cb.getX(inputVector[2][0]);
                            int y1 = cb.getY(inputVector[2][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y1 && j == x1 - 1) {
                                        PieceType currentP = cb.chessBoard[i][j].p;
                                        Colour currentC = cb.chessBoard[i][j].c;
                                        if (currentC == Colour::Black && currentP == PieceType::King) {
                                            blackKing -= 1;
                                        }
                                        if (currentC == Colour::White && currentP == PieceType::King) {
                                            whiteKing -= 1;
                                        }
                                        Tile newT = {i, j, Colour::NoColour, PieceType::NoPiece};
                                        cb.chessBoard[i][j] = newT;
                                        cout << cb;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        continue;
                                    }
                                }
                            }
                        } else if (inputVector[1] == "=") {
                            if (inputVector[2] == "black") {
                                isWhiteTurn = false;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            } else if (inputVector[2] == "white") {
                                isWhiteTurn = true;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            } else {
                                cout << "Invalid input! Please enter command again!" << endl;
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                continue;
                            }
                        } 
                    } else if (inputVector.size() == 2) {
                        if (inputVector[1] == "done") { 
                            for (int i = 0; i < 8; ++i) {
                                if (invalidSetup) {
                                    break;
                                }
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 0 || i == 7) {
                                        if (cb.chessBoard[i][j].p == PieceType::Pawn || cb.chessBoard[i][j].p == PieceType::Pawn) {
                                            invalidSetup = true;
                                            cout << "Invalid setup! You can not place Pawn on the first or last row!" << endl;
                                            inputVector.clear();
                                            inputVector.emplace_back("setup");
                                            break;
                                        }
                                    } 
                                    if (whiteKing != 1) {
                                        invalidSetup = true;
                                        cout << "Invalid setup! You need ONE White King!." << endl;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        break;
                                    }
                                    if (blackKing != 1) {
                                        invalidSetup = true;
                                        cout << "Invalid setup! You need ONE Black King!." << endl;
                                        inputVector.clear();
                                        inputVector.emplace_back("setup");
                                        break;
                                    }
                                }
                            }
                            if (invalidSetup) {
                                inputVector.clear();
                                inputVector.emplace_back("setup");
                                invalidSetup = false;
                                continue;
                            } else {
                                inputVector.clear();
                                break;
                            }
                        }
                    }
                }
                if (!invalidSetup) {
                    continue;
                }
            } else {
                cout << "Invalid input! Please enter command again!" << endl;
                inputVector.clear();
                continue;
            }
        } else if (inputVector.size() == 3) {
            if (inputVector[0] == "game") {
                // Initialize Player 1
                if (inputVector[1] == "human") {
                    Human * playerOne = new Human();
                } else if (inputVector[1].substr(0, 8) == "computer") {
                    char levelChar = inputVector[1][9];
                    int level = levelChar - '0';
                    if (0 < level &&  level < 5) {
                        Computer * playerOne = computerInitialization(level);
                    } else {
                        cout << "Invalid input! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                } else {
                    cout << "Invalid input! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
                // Initialize Player 2 
                if (inputVector[2] == "human") {
                    Human * playerTwo = new Human();
                    inputVector.clear();
                    cb.init();
                    cout << cb;
                } else if (inputVector[2].substr(0, 8) == "computer") {
                    char levelChar = inputVector[2][9];
                    int level = levelChar - '0';
                    if (0 < level &&  level < 5) {
                        Computer * playerTwo = computerInitialization(level);
                        inputVector.clear();
                        cb.init();
                        cout << cb;
                    } else {
                        cout << "Invalid input! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                } else {
                    cout << "Invalid input! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
            } else if (inputVector[0] == "move") {
                int x1 = cb.getX(inputVector[1][0]);
                int y1 = cb.getY(inputVector[1][1]);
                int x2 = cb.getX(inputVector[2][0]);
                int y2 = cb.getY(inputVector[2][1]);
                Colour wT = whichTurn(x1, y1, cb);
                Tile tile1;
                Tile tile2;
                if (isWhiteTurn && whichTurn(x1, y1, cb) != Colour::White) {
                    cout << "Invalid input! It is White's turn!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && whichTurn(x1, y1, cb) != Colour::Black) {
                    cout << "Invalid input! It is Black's turn!" << endl;
                    inputVector.clear();
                    continue;
                }
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (i == 8 - y1 && j == x1 - 1) {
                           tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                        if (i == 8 - y2 && j == x2 - 1) {
                           tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                    }
                }
                // Adjust if king or rook hasnt moved 
                string castTest = isCastling(inputVector[1], inputVector[2], cb);
                if (isCastlingLegal(castTest, cb)) {
                    // change chessboard
                    if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                        cout << "Invalid move! White will be in check!" << endl;
                        cout << cb;;
                        inputVector.clear();
                        continue;
                    } else if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                        cout << "Invalid move! Black will be in check!" << endl;
                        cout << cb;;
                        inputVector.clear();
                        continue;
                    }
                    Tile t1;
                    Tile t2;
                    Tile t3;
                    Tile t4;
                    if (castTest == "wr") {
                        t1 = {5, 1, Colour::NoColour, PieceType::NoPiece};
                        t2 = {8, 1, Colour::NoColour, PieceType::NoPiece};
                        t3 = {6, 1, Colour::White, PieceType::Castle};
                        t4 = {7, 1, Colour::White, PieceType::King};
                        cb.chessBoard[7][4] = t1;
                        cb.chessBoard[7][7] = t2;
                        cb.chessBoard[7][5] = t3;
                        cb.chessBoard[7][6] = t4;
                        cb.castlingWhiteAllowedRight = false;
                    } else if (castTest == "wl") {
                        t1 = {5, 1, Colour::NoColour, PieceType::NoPiece};
                        t2 = {1, 1, Colour::NoColour, PieceType::NoPiece};
                        t3 = {4, 1, Colour::White, PieceType::Castle};
                        t4 = {3, 1, Colour::White, PieceType::King};
                        cb.chessBoard[7][4] = t1;
                        cb.chessBoard[7][0] = t2;
                        cb.chessBoard[7][3] = t3;
                        cb.chessBoard[7][2] = t4;
                        cb.castlingWhiteAllowedLeft = false;
                    } else if (castTest == "br") {
                        t1 = {5, 8, Colour::NoColour, PieceType::NoPiece};
                        t2 = {8, 8, Colour::NoColour, PieceType::NoPiece};
                        t3 = {6, 8, Colour::Black, PieceType::Castle};
                        t4 = {7, 8, Colour::Black, PieceType::King};
                        cb.chessBoard[0][4] = t1;
                        cb.chessBoard[0][7] = t2;
                        cb.chessBoard[0][5] = t3;
                        cb.chessBoard[0][6] = t4;
                        cb.castlingBlackAllowedRight = false;
                    } else if (castTest == "bl") {
                        t1 = {5, 8, Colour::NoColour, PieceType::NoPiece};
                        t2 = {1, 8, Colour::NoColour, PieceType::NoPiece};
                        t3 = {4, 8, Colour::Black, PieceType::Castle};
                        t4 = {3, 8, Colour::Black, PieceType::King};
                        cb.chessBoard[0][4] = t1;
                        cb.chessBoard[0][0] = t2;
                        cb.chessBoard[0][3] = t3;
                        cb.chessBoard[0][2] = t4;
                        cb.castlingBlackAllowedLeft = false;;
                    }
                    if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                        } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                    }
                    cout << cb;
                    inputVector.clear();
                    continue;
                } 
                if (IsLegal(tile1, tile2, cb)) {
                    if (IsValid(tile1, tile2, cb)) {
                        if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                            cout << "Invalid move! White will be in check!" << endl;
                            cout << cb;;
                            inputVector.clear();
                            continue;
                        } else if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                            cout << "Invalid move! Black will be in check!" << endl;
                            cout << cb;;
                            inputVector.clear();
                            continue;
                        }
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                // Check for castling condition
                                if (tile1.p == PieceType::King && tile1.c == Colour::White) {
                                    cb.castlingWhiteAllowedLeft = false;
                                    cb.castlingWhiteAllowedRight = false;
                                } else if (tile1.p == PieceType::King && tile1.c == Colour::Black) {
                                    cb.castlingBlackAllowedRight = false;
                                    cb.castlingBlackAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::White && tile1.num == 1 && tile1.alphabet == 1) {
                                    cb.castlingWhiteAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::White && tile1.num == 1 && tile1.alphabet == 8) {
                                    cb.castlingWhiteAllowedRight = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::Black && tile1.num == 8 && tile1.alphabet == 1) {
                                    cb.castlingBlackAllowedLeft = false;
                                } else if (tile1.p == PieceType::Castle && tile1.c == Colour::Black && tile1.num == 8 && tile1.alphabet == 8) {
                                    cb.castlingBlackAllowedRight = false;
                                }
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        // Change turns
                        if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                        } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                        }
                    } else {
                        cout << "Invalid move! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                    if (!isWhiteTurn && cb.isBlackCheck(cb, tile1, tile2, inputVector)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        cout << "Black is in check!" << endl;
                    } else if (isWhiteTurn && cb.isWhiteCheck(cb, tile1, tile2, inputVector)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    Tile newT = {x2, y2, tile1.c, tile1.p};
                                    cb.chessBoard[i][j] = newT;
                                } 
                            }
                        }
                        cout << "White is in check!" << endl;
                    }
                    cout << cb;
                    inputVector.clear();
                    continue;
                } else {
                    cout << "Invalid move! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
            } else {
                cout << "Invalid input! Please enter command again!" << endl;
                inputVector.clear();
                continue;
            }
        } else if (inputVector.size() == 4) {
            if (inputVector[0] == "move") {
                cout << "inside right move" << endl;
                int x1 = cb.getX(inputVector[1][0]);
                int y1 = cb.getY(inputVector[1][1]);
                int x2 = cb.getX(inputVector[2][0]);
                int y2 = cb.getY(inputVector[2][1]);
                PieceType pPiece = whichPiece(inputVector[3]);
                if (pPiece == PieceType::Pawn || pPiece == PieceType::King) {
                    cout << "Invalid input! Promotion piece can be either of Rook, Knight, Bishop or Queen!" << endl;
                    inputVector.clear();
                    continue;
                }
                Colour pColour = whichColour(inputVector[3]);
                if (isWhiteTurn && pColour != Colour::White) {
                    cout << "Invalid input! It is White's turn! Promotion piece must be White!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && pColour != Colour::Black) {
                    cout << "Invalid input! It is Black's turn! Promotion piece must be Black" << endl;
                    inputVector.clear();
                    continue;
                }
                if (isWhiteTurn && whichTurn(x1, y1, cb) != Colour::White) {
                    cout << "Invalid input! It is White's turn!" << endl;
                    inputVector.clear();
                    continue;
                } else if (!isWhiteTurn && whichTurn(x1, y1, cb) != Colour::Black) {
                    cout << "Invalid input! It is Black's turn!" << endl;
                    inputVector.clear();
                    continue;
                }
                Tile tile1;
                Tile tile2;
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (i == 8 - y1 && j == x1 - 1) {
                           tile1 = {x1, y1, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                        if (i == 8 - y2 && j == x2 - 1) {
                           tile2 = {x2, y2, cb.chessBoard[i][j].c, cb.chessBoard[i][j].p};
                        }
                    }
                }
                if (IsLegal(tile1, tile2, cb)) {
                    if (IsValid(tile1, tile2, cb)) {
                        for (int i = 0; i < 8; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (i == 8 - y1 && j == x1 - 1) {
                                    Tile newT = {x1, y1, Colour::NoColour, PieceType::NoPiece};
                                    cb.chessBoard[i][j] = newT;
                                }
                                if (i == 8 - y2 && j == x2 - 1) {
                                    cout << "coming inside" << endl;
                                    if (tile1.p == PieceType::Pawn && tile1.c == Colour::White && i == 0) {
                                        cout << "deep inside" << endl;
                                        Tile newT = {x2, y2, tile1.c, pPiece};
                                        cb.chessBoard[i][j] = newT;
                                    } else if (tile1.p == PieceType::Pawn && tile1.c == Colour::Black && i == 7) {
                                        Tile newT = {x2, y2, tile1.c, pPiece};
                                        cb.chessBoard[i][j] = newT;
                                    } else {
                                        Tile newT = {x2, y2, tile1.c, tile1.p};
                                        cb.chessBoard[i][j] = newT;
                                    } 
                                } 
                            }
                        }
                        if (isWhiteTurn == true) {
                            isWhiteTurn = false;
                         } else if (isWhiteTurn == false) {
                            isWhiteTurn = true;
                        }
                    } else {
                        cout << "Invalid move! Please enter command again!" << endl;
                        inputVector.clear();
                        continue;
                    }
                    cout << cb;
                    inputVector.clear();
                    continue;
                } else {
                    cout << "Invalid move! Please enter command again!" << endl;
                    inputVector.clear();
                    continue;
                }
            } else {
                cout << "Invalid input! Please enter command again!" << endl;
                inputVector.clear();
                continue;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include "human.h"
#include "computer.h"
#include "chessboard.h"

using namespace std;

int getX(char s) {
    if (s == 'a') {
        return 1;
    } else if (s == 'b') {
        return 2;
    } else if (s == 'c') {
        return 3;
    } else if (s == 'd') {
        return 4;
    } else if (s == 'e') {
        return 5;
    } else if (s == 'f') {
        return 6;
    } else if (s == 'g') {
        return 7;
    } else if (s == 'h') {
        return 8;
    }
}

int getY(char s) {
    int row = s - '0';
    return row;
}

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
    string input;
    vector <string> inputVector; 
    ChessBoard cb;
    bool whiteTurn = true;
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
        if (inputVector.size() == 1 || inputVector.size() == 4) {
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
                            int x = getX(inputVector[3][0]);
                            int y = getY(inputVector[3][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y && j == x - 1) {
                                        PieceType currentP = cb.chessBoard[i][j].p;
                                        Colour currentC = cb.chessBoard[i][j].c;
                                        if (currentC == Colour::Black && currentP == PieceType::King) {
                                            blackKing -= 1;
                                        }
                                        if (currentC == Colour::White && currentP == PieceType::King) {
                                            whiteKing -= 1;
                                        }
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
                            int x1 = getX(inputVector[2][0]);
                            int y1 = getY(inputVector[2][1]);
                            for (int i = 0; i < 8; ++i) {
                                for (int j = 0; j < 8; ++j) {
                                    if (i == 8 - y1 && j == x1 - 1) {
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
                                whiteTurn = false;
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
                int x1 = getX(inputVector[1][0]);
                int y1 = getY(inputVector[1][1]);
                int x2 = getX(inputVector[2][0]);
                int y2 = getY(inputVector[2][1]);
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
                if (IsLegal(tile1, tile2)) {
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
                    cout << cb;
                    inputVector.clear();
                    continue;
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
        } else {
            cout << "Invalid input! Please enter command again!" << endl;
            inputVector.clear();
            continue;
        }
    }
    return 0;
}
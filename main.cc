#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include "human.h"
#include "computer.h"
#include "chessboard.h"

using namespace std;

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
        if (inputVector.size() == 1) {
            if (inputVector[0] == "resign") {
                break;
            } else if (inputVector[0] == "setup") {

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
                    break;
                } else if (inputVector[2].substr(0, 8) == "computer") {
                    char levelChar = inputVector[2][9];
                    int level = levelChar - '0';
                    if (0 < level &&  level < 5) {
                        Computer * playerTwo = computerInitialization(level);
                        inputVector.clear();
                        cb.init();
                        cout << cb;
                        break;
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
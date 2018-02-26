#include "board.h"
#include "conio.h"
#include <iostream>

using namespace std;

board::board() {
    setMatrix();
    setShips();
    printMatrix(false, 0, 0);
}

void board::setMatrix() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[j][i] = '~';
        }
    }
}

void board::setShips() {
    for (int j = 0; j < 5; j++) {
        matrix[0][j] = '#';
    }
    matrix[2][3] = '#';
    matrix[3][3] = '#';
}

void board::printMatrix(bool peek, int count, int count2) {
    cout << "   A B C D E" << endl;
    int yLabel = 1;
    for (int i = 0; i < 5; i++) {
        cout << yLabel << " ";
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] == '#') {
                if (peek) {
                    cout << " " << matrix[j][i];
                }
                else {
                    cout << " " << conio::bgColor(conio::LIGHT_BLUE) << conio::fgColor(conio::BLACK) << "~" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE);
                }
            }
            else if (matrix[j][i] == 'X') {
                if (count == 5 && j==0) {
                    cout << " " << conio::bgColor(conio::RED) << "@" << conio::bgColor(conio::BLACK);
                }
                else if (count2 == 2 && (j==2 || j==3) && (i==3)) {
                    cout << " " << conio::bgColor(conio::RED) << "@" << conio::bgColor(conio::BLACK);
                }
                else {
                    cout << " " << conio::bgColor(conio::LIGHT_YELLOW) << conio::fgColor(conio::BLACK) << "X" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE);
                }
            }
            else if (matrix[j][i] == 'O') {
                cout << " " << conio::bgColor(conio::GREEN) << conio::fgColor(conio::BLACK) << "O" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE);
            }
            else {
                cout << " " << conio::bgColor(conio::LIGHT_BLUE) << conio::fgColor(conio::BLACK) << "~" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE);
            }
        }
        yLabel++;
        cout << endl;
    }
}

char board::getCoords(int xCoord, int yCoord) {
    return matrix[yCoord][xCoord];
}

void board::setHit(int xCoord, int yCoord) {
    matrix[yCoord][xCoord] = 'X';
}

void board::setMiss(int xCoord, int yCoord) {
    matrix[yCoord][xCoord] = 'O';
}

void board::setSunk(int xCoord, int yCoord) {
    matrix[yCoord][xCoord] = '@';
}

int board::isSunk() {
    int count = 0;
    for (int j = 0; j < 5; j++) {
        if (matrix[0][j] == 'X') {
            count++;
        }
    }
    return count;
}

int board::isSunk2() {
    int count2 = 0;
    if (matrix[2][3] == 'X') {
        count2++;
    }
    if (matrix[3][3] == 'X') {
        count2++;
    }
    return count2;
}
#include "conio.h"
#include "board.h"
#include <iostream>

using namespace std;

int main() {
	char xInput;
	int yInput;
	int xCoordinate = 0;
	int yCoordinate = 0;

	board matrix1;

	while(true) {
		cout << "Enter X coordinate (between A and E) or enter P to peek: ";
		cin >> xInput;
		
		xInput = static_cast<char>(tolower(xInput));
		while (xInput != 'a' && xInput != 'b' && xInput != 'c' && xInput != 'd' && xInput != 'e' && xInput != 'p') {
				cout << "X coordinate must be between A and E: ";
				cin >> xInput;
				xInput = static_cast<char>(tolower(xInput));
		}
		if (xInput == 'a') {
			xCoordinate = 0;
		}
		if (xInput == 'b') {
			xCoordinate = 1;
		}
		if (xInput == 'c') {
			xCoordinate = 2;
		}
		if (xInput == 'd') {
			xCoordinate = 3;
		}
		if (xInput == 'e') {
			xCoordinate = 4;
		}
		if (xInput == 'p') {
			cout << conio::clrscr() << conio::gotoRowCol(0, 0);
			cout << "Peeking..." << endl;
			matrix1.printMatrix(true, 0, 0);
			continue;
		}

		cout << "Enter Y coordinate (between 1 and 5): ";
		cin >> yInput;

		while (yInput != 1 && yInput != 2 && yInput != 3 && yInput != 4 && yInput != 5) {
				cout << "Y coordinate must be between 1 and 5: ";
				cin >> yInput;
		}
		yCoordinate = yInput - 1;

		// cout << xCoordinate << " " << yCoordinate << endl;
		// cout << matrix1.getCoords(xCoordinate, yCoordinate) << endl;

		cout << conio::clrscr() << conio::gotoRowCol(0, 0);

		if (matrix1.getCoords(yCoordinate, xCoordinate) == 'X' || matrix1.getCoords(yCoordinate, xCoordinate) == 'O') {
			cout << "You already shot there!" << endl;
		}
		if (matrix1.getCoords(yCoordinate, xCoordinate) == '#') {
			cout << conio::bgColor(conio::LIGHT_YELLOW) << conio::fgColor(conio::BLACK) << "Hit!" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE) << endl;
			matrix1.setHit(yCoordinate, xCoordinate);
		}
		if (matrix1.getCoords(yCoordinate, xCoordinate) == '~') {
			cout << conio::bgColor(conio::GREEN) << conio::fgColor(conio::BLACK) << "Miss!" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE) << endl;
			matrix1.setMiss(yCoordinate, xCoordinate);
		}

		cout << endl;

		if (xInput != 'p') {
			matrix1.printMatrix(false, matrix1.isSunk(), matrix1.isSunk2());
		}

		if (matrix1.getCoords(yCoordinate, xCoordinate) == '@') {
			cout << conio::bgColor(conio::RED) << "Sunk!" << conio::bgColor(conio::BLACK) << endl;
		}

		cout << endl;
		cout << endl;
		cout << "LEGEND:" << endl;
		cout << "Water = " << conio::bgColor(conio::LIGHT_BLUE) << conio::fgColor(conio::BLACK) << "~" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE) << endl;
		cout << "Miss = " << conio::bgColor(conio::GREEN) << conio::fgColor(conio::BLACK) << "O" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE) << endl;
		cout << "Hit = " << conio::bgColor(conio::LIGHT_YELLOW) << conio::fgColor(conio::BLACK) << "X" << conio::bgColor(conio::BLACK) << conio::fgColor(conio::WHITE) << endl;
		cout << "Sunk = " << conio::bgColor(conio::RED) << "@" << conio::bgColor(conio::BLACK) << endl;
		cout << endl;
	}
}
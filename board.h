class board {
private:
    char matrix[5][5];
    int count;
    int count2;
public:
	board();
	void setMatrix();
	void setShips();
	void printMatrix(bool, int, int);
	char getCoords(int, int);
	void setHit(int, int);
	void setMiss(int, int);
	void setSunk(int, int);
	int isSunk();
	int isSunk2();
};
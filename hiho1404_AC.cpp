#include <iostream>

#define MAXN 20

char board[MAXN][MAXN];
int size = 15;
bool debug = false;

void outputBoard() {
	std::cout << "-----" << std::endl;
	for (int i = 0; i < size; i++) std::cout << board[i] << std::endl;
	std::cout << "-----" << std::endl;
}

bool search(int row, int col) {
	int i;
	//horizontally
	if (col + 4 < size) {
		for (i = 1; i <= 4; i++) {
			if (board[row][col + i] != board[row][col]) break; 
		}
		if (i == 5) return true;
	}
	//vertically
	if (row + 4 < size) {
		for (i = 1; i <= 4; i++) {
			if (board[row + i][col] != board[row][col]) break; 
		}
		if (i == 5) return true;
	}
	//diagonally
	if (row + 4 < size && col + 4 < size) {
		for (i = 1; i <= 4; i++) {
			if (board[row + i][col + i] != board[row][col]) break; 
		}
		if (i == 5) return true;
	}
	//
	if (row + 4 < size && col - 4 >= 0) {
		for (i = 1; i <= 4; i++) {
			if (board[row + i][col - i] != board[row][col]) break; 
		}
		if (i == 5) return true;
	}
	return false;
}

int main() {
	int testCase;
	bool winB, winW;
	std::cin >> testCase;
	while (testCase--) {
		int i = 0, j = 0;
		winB = false;
		winW = false;
		for (i = 0; i < size; i++) std::cin >> board[i];

		if (debug) {
			outputBoard();
		}

		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if (board[i][j] == '.') continue;
				
				if (winB && board[i][j] == 'B') continue;
				if (winW && board[i][j] == 'W') continue;
				if (search(i, j) ) {
					if (board[i][j] == 'B') winB = true;
					else winW = true;
				}
				if (winB && winW) break;
			}
			if (winB && winW) break;
		}
		if (winB) {
			if (!winW) std::cout << "Black" << std::endl;
			else std::cout << "Both" << std::endl;
		}
		else {
			if (winW) std::cout << "White" << std::endl;
			else std::cout << "None" << std::endl;
		}
	}
	return 0;
}

#include <iostream>

#define MAX 1005

int map[MAX][MAX] = {0};
int totalrow, totalcol;
void search(int row, int col) {
	for (int r = row - 1; r >= 0; r--) {
		if (map[r][col] == -1) break;
		map[r][col]++;
	}
	for (int r = row + 1; r < totalrow;  r++) {
		if (map[r][col] == -1) break;
		map[r][col]++;
	}
	for (int c = col - 1; c >= 0; c--) {
		if (map[row][c] == -1) break;
		map[row][c]++;
	}
	for (int c = col + 1; c < totalcol; c++) {
		if (map[row][c] == -1) break;
		map[row][c]++;
	}
/*	for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--,c--) {
		if (map[r][c] == -1) break;
		map[r][c]++;
	}
	for (int r = row - 1, c = col + 1; r >= 0 && c < totalcol; r--,c++) {
		if (map[r][c] == -1) break;
		map[r][c]++;
	}
	for (int r = row + 1, c = col - 1; r < totalrow && c >= 0; r++,c--) {
		if (map[r][c] == -1) break;
		map[r][c]++;
	}
	for (int r = row + 1, c = col + 1; r < totalrow && c < totalcol; r++,c++) {
		if (map[r][c] == -1) break;
		map[r][c]++;
	}*/
}

int main() {
	std::cin >> totalrow >> totalcol;
	char c;
	for (int i = 0; i < totalrow; i++) {
		for (int j = 0; j < totalcol; j++) {
			std::cin >> c;
			if (c == 'O') continue;
			else map[i][j] = -1;
		}
	}

	for (int i = 0; i < totalrow; i++) {
		for (int j = 0; j < totalcol; j++) {
			if (map[i][j] != -1) continue;
			search(i, j);
		}
	}

	for (int i = 0; i < totalrow; i++) {
		for (int j = 0; j < totalcol; j++) {
			if (map[i][j] == -1) std::cout << "B";
			else std::cout << map[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}

#include <iostream>
#include <cstring>
#include <string>

#define MAXN 205

int rows, cols;
//-1 unknow, 0-8 numOfBoom 
int maps[MAXN][MAXN];
//-1 No, 0 unsure, 1 Yes
int isBoom[MAXN][MAXN];

void init() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			isBoom[i][j] = 0;
		}
	}
}

int sumOfUnCheck(int r, int c) {
	int sum = 0;
	for (int x = r - 1; x <= r + 1; x++) {
		for (int y = c - 1; y <= c + 1; y++) {
			if (x < 0 || y < 0 || x >= rows || y >= cols) continue;
			if (isBoom[x][y] != -1) sum++;
		}
	}
	return sum;
}

int checkNeighbor(int i, int j, int x, int y) {
		
}

void check() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (maps[i][j] <= 0) continue;
			if (sumOfUnCheck(i, j) == maps[i][j])
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; y <= j + 1; y++) {
					if (x < 0 || x >= rows || y < 0 || y >= cols) continue;
					if (isBoom[x][y] != -1) isBoom[x][y] = 1;
				}
			}
		}
	}

	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			if (maps[i][j] < 0) continue;
			for (int x = i - 2; x < i; x++) {
				for (int y = j - 2; y < j; y++) {
					if (x < 0 || y < 0 || maps[x][y] < 0) continue;
					checkNeighbor(i, j, x, y);
				}
			}
		}
	}
}

void input() {
	std::cin >> numOfCase;
	while (numOfCase--) {
		std::cin >> rows >> cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cin >> maps[i][j];
				if (maps[i][j] != -1) isBoom[i][j] = -1;
				if (maps[i][j] == 0) {
					if (i > 0) {
						isBoom[i - 1][j] = -1;
						if (j > 0) isBoom[i - 1][j - 1] = -1;
						if (j < cols - 1) isBoom[i - 1][j + 1] = -1;
					}
					if (j > 0) isBoom[i][j - 1] = -1;
					if (j < cols - 1) isBoom[i][j + 1] = -1;
					if (i < rows - 1) {
						isBoom[i + 1][j] = -1;
						if (j > 0) isBoom[i + 1][j - 1] = -1;
						if (j < cols - 1) isBoom[i + 1][j + 1] = -1;
					}
				}
			}
		}
		check();
	}
}

int main() {
	input();

	return 0;
}

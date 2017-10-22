#include <iostream>
#include <cstring>
#include <string>

#define MAXN 1000
char data[MAXN][MAXN];
int colors[MAXN][MAXN];
int totalRow, totalCol;

void dfs(int row, int col, int color) {	
	if (colors[row][col] != 0) return;
	colors[row][col] = color;
	if (data[row][col] == '-' || data[row][col] == '+' || data[row][col] == '*') {
		if (row > 0) dfs(row-1, col, color);
		if (row < totalRow - 1) dfs(row+1, col, color);
	}
	if (data[row][col] == '|' || data[row][col] == '+' || data[row][col] == '*') {
		if (col > 0) dfs(row, col-1, color);
		if (col < totalCol - 1) dfs(row, col+1, color);
	}
	if (data[row][col] == '/' || data[row][col] == '*') {
		if (row > 0 && col < totalCol - 1) dfs(row-1, col+1, color);
		if (row < totalRow - 1 && col > 0) dfs(row+1, col-1, color);
	}
	if (data[row][col] == '\\' || data[row][col] == '*') {
		if (row > 0 && col > 0) dfs(row-1, col-1, color);
		if (row < totalRow - 1 && col < totalCol - 1) dfs(row+1, col+1, color);
	}
}

void init(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			data[i][j] = ' ';
			colors[i][j] = 0;
		}
	}
}

int main() {
	int numOfColor;
	std::string str;
	int row, col, color;
	std::cin >> totalRow >> totalCol;

	init(totalRow, totalCol);

	for (int x = 0; x < totalRow; x++) {
		getline(std::cin, str);
		int len = str.length();
		for (int y = 0; y < len; y++) {
			data[x][y] = str[y];
			if (data[x][y] == '\n') break;
		}
	}
	std::cin >> numOfColor;
	while(numOfColor--) {
		std::cin >> row >> col >> color;		
		dfs(row, col, color);
	}
	/*
	for (int x = 0; x < totalRow; x++) {
		for (int y = 0; y < totalRow; y++) {
			std::cout << colors[x][y] << " ";
		}
		std::cout << std::endl;
	}
	*/
	for (int x = 0; x < totalRow; x++) {
		int y = 0;
		bool flag = false;
		while(y < totalCol) {
			if (flag) std::cout << data[x][y];
			else if (colors[x][y] == 0) {
				if (flag) {
				       flag = false;
				       std::cout << "m]";
				}
				std::cout << data[x][y];
			}
			else {
				flag = true;
				std::cout << "[m" << colors[x][y] << data[x][y];
			}
			y++;
		}
		std::cout << std::endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>

#define MAXN 1000
char data[MAXN][MAXN];
int colors[MAXN][MAXN];
int totalRow, totalCol;

void dfs(int row, int col, int color) {
	colors[row][col] = color;
	if (row > 1) dfs(row-1, col, color);
	if (row < totalRow - 1) dfs(row+1, col, color);
	if (col > 1) dfs(row, col-1, color);
	if (col < totalCol - 1) dfs(row, col+1, color);

}

int main() {
	int numOfColor;
	int row, col, color;
	std::cin >> totalRow >> totalCol;
	memset(data, 0, sizeof(data));
	memset(colors, 0, sizeof(colors));
	for (int x = 0; x < totalRow; x++) {
		for (int y = 0; y < totalCol; y++) {
			std::cin >> data[x][y];
		}
	}
	std::cin >> numOfColor;
	while(numOfColor--) {
		std::cin >> row >> col >> color;
		dfs(row, col, color);
	}
	return 0;
}

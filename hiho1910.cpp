#include <iostream>

#define MAXN 1005
char map[MAXN][MAXN] = {0};
int totalWidth, totalHeight;

class Node {
public:
	int row;
	int col;
	int scale;
	int num;
	Node(int _r = 0, int _c = 0, int _s = 0, int _n = 0) {
		row = _r;
		col = _c;
		scale = _s;
		num = _n;
	}
};

Node search(int row, int col) {
	Node res;
	
	int rscale = 1, cscale = 1;
	int c = col + 1, r = row + 1;
	while (c < totalWidth && map[row][c] == '#') {
		c++;
		rscale++;
	}
	while (r < totalHeight && map[r][col] == '#') {
		r++;
		cscale++;
	}
	if (rscale < 3) res = Node(row, col, rscale, 5); //count5
	else if (cscale < 3) res = Node(row, col, rscale, 2); //count2
	else {
		if (map[row + 1][col + rscale - 1] == '#') 
			res = Node(row, col, rscale, 2);//count2;
		else res = Node(row, col, rscale, 5);//count5	
	}
	return res;
}

int main() {
	int numOfCase;
	int count2, count5;
	std::cin >> numOfCase;
	while(numOfCase--) {
		std::cin >> totalWidth >> totalHeight;
		for (int i = 0; i < totalHeight; i++) {
			std::cin >> map[i];
		}
		count2 = 0;
		count5 = 0;

		for (int i = 0; i <= totalHeight - 3; i++) {
			for (int j = 0; j <= totalWidth - 3; j++) {
				if (map[i][j] == '.') continue;
				search(i, j);

		std::cout << std::endl;
	}
	return 0;
}

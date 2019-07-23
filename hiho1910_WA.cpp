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
	bool horizontal;
	Node(int _r = 0, int _c = 0, int _s = 0, int _n = 0, bool _h = false) {
		row = _r;
		col = _c;
		scale = _s;
		num = _n;
		horizontal = _h;
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
	if (rscale < 3) res = Node(row, col, cscale, 5, true); //count5
	else if (cscale < 3) res = Node(row, col, rscale, 2, false); //count2
	else {
		if (map[row + 1][col + rscale - 1] == '#') 
			res = Node(row, col, rscale, 2, true);//count2;
		else res = Node(row, col, rscale, 5, false);//count5	
	}
	return res;
}

void fillNode(Node node) {
	int height = node.scale, width = node.scale;
	if (node.horizontal) width = node.scale * 2 - 1;
	else height = node.scale * 2 - 1;
	for (int i = node.row; i < node.row + height; i++) {
		for (int j = node.col; j < node.col + width; j++) {
			map[i][j] = '.';
		}
	}
}

void output() {
	for (int i = 0; i < totalHeight; i++) {
		for (int j = 0; j < totalWidth; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

int main() {
	int numOfCase;
	int count2, count5;
	std::cin >> numOfCase;
	while(numOfCase--) {
		std::cin >> totalHeight >> totalWidth;
		for (int i = 0; i < totalHeight; i++) {
			std::cin >> map[i];
		}
		count2 = 0;
		count5 = 0;

		for (int i = 0; i <= totalHeight - 3; i++) {
			for (int j = 0; j <= totalWidth - 3; j++) {
				if (map[i][j] == '.') continue;	
				Node node = search(i, j);
				if (node.num == 2) count2++;
				else count5++;
				fillNode(node);

				//std::cout << node.num << " " << node.scale << " " << node.row << " " << node.col << std::endl;
				//output();
	}
		}
		std::cout << count2 << " " << count5 << std::endl;
	}
	return 0;
}

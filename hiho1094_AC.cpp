#include <iostream>

#define MAXN 201

char data[MAXN][MAXN];
char target[3][3];

int sameN(int x, int y) { // 1:N 2:E 3:S 4:W
	if (target[0][1] == data[x - 1][y] && target[1][0] == data[x][y - 1] && target[1][2] == data[x][y + 1] && target[2][1] == data[x + 1][y] ) return 1;
	if (target[0][1] == data[x][y + 1] && target[1][0] == data[x - 1][y] && target[1][2] == data[x + 1][y] && target[2][1] == data[x][y - 1] ) return 2;
	if (target[0][1] == data[x + 1][y] && target[1][0] == data[x][y + 1] && target[1][2] == data[x][y - 1] && target[2][1] == data[x - 1][y] ) return 3;
	if (target[0][1] == data[x][y - 1] && target[1][0] == data[x + 1][y] && target[1][2] == data[x - 1][y] && target[2][1] == data[x][y + 1] ) return 4;
	return 0;
}

bool same(int x, int y) {
	if (target[1][1] != data[x][y]) return false;
	switch (sameN(x, y) ) {
	case 1:
		if (target[0][0] == data[x-1][y-1] && target[0][2] == data[x-1][y+1] && target[2][0] == data[x+1][y-1] && target[2][2] == data[x+1][y+1]) return true;
		break;
	case 2:
		if (target[0][0] == data[x-1][y+1] && target[0][2] == data[x+1][y+1] && target[2][0] == data[x-1][y-1] && target[2][2] == data[x+1][y-1]) return true;
		break;
	case 3:
		if (target[0][0] == data[x+1][y+1] && target[0][2] == data[x+1][y-1] && target[2][0] == data[x-1][y+1] && target[2][2] == data[x-1][y-1]) return true;
		break;
	case 4:
		if (target[0][0] == data[x+1][y-1] && target[0][2] == data[x-1][y-1] && target[2][0] == data[x+1][y+1] && target[2][2] == data[x-1][y+1]) return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}

int main() {
	int totalRow, totalCol;
	std::cin >> totalRow >> totalCol;
	for (int i = 0; i < totalRow; i++) {
		std::cin >> data[i];
	}
	for (int i = 0; i < 3; i++) {
		std::cin >> target[i];
	}
	for (int i = 1; i < totalRow - 1; i++) {
		for (int j = 1; j < totalCol - 1; j++) { 
			if (same(i, j)) std::cout << i + 1 << " " << j + 1 << std::endl;		
		}
	}	
		
	return 0;
}

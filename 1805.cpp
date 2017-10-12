#include <iostream>
#include <cstring>
#include <string>

#define MAXN 128

long long image[MAXN][MAXN];
int block[8] = {1£¬2£¬4, 8, 16, 32, 64, 128};

long long calculate(int tarRow, int tarCol, int level) {
	long long result = 0;
	int calRow = tarRow - level, calCol = tarCol - level;
	result = image[calRow][calCol];
	calCol = tarCol;
	result = (result << level) + image[calRow][calCol];
	calRow = tarRow;
	calCol = tarCol - level;
	result = (result << level) + image[calRow][calCol];
	calCol = tarCol;
	result = (result << level) + image[calRow][calCol];
	return result;
}



int main() {
	int numOfRow, numOfCol;
	int actRow, actCol, tmp;
	long long resultQuad, resultSquad;
	while (1) {
		//input
		std::cin >> numOfRow >> numOfCol;
		if (numOfRow == 0 && numOfCol == 0) break;
		memset(image, 0, sizeof(image));
		int i = 0;
		while(numOfRow < block[i]) i++;
		actRow = block[i] / 2;
		i = 0;
		while(numOfCol < block[i]) i++;
		actCol = block[i] / 2;
		for (i = 0; i < numOfRow; i++) {
			for (int j = 0; j < numOfCol; j++) {
				std::cin >> tmp;
				image[i/2][j/2] = (image[i/2][j/2] << 1) + tmp;
			}
		}
		//
		//output
		std::cout << std::endl;
	}
	return 0;
}

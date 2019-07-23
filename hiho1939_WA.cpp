#include <iostream>

#define MAXN 105

char map[MAXN][MAXN] = {0};
int mapNum[MAXN][MAXN] = {0};
int numOfEdge;

int main() {
	std::cin >> numOfEdge;
	for (int i = 1; i <= numOfEdge; i++) {
		std::cin >> map[i];
	}
	for (int i = 1; i <= numOfEdge; i++) {
		for (int j = 0; j < 2 * i - 1; j++) {
			if (map[i][j] == '*') {
				std::cout << "*";
				continue;
			}
			if (j > 0 && map[i][j - 1] == '*') mapNum[i][j]++;
			if (j < 2*i - 2 && map[i][j + 1] == '*') mapNum[i][j]++;
			if (j % 2 == 0) {
				if (i < numOfEdge && map[i + 1][j + 1] == '*') mapNum[i][j]++; 
			} else {
				if (i > 1 && map[i - 1][j - 1] == '*') mapNum[i][j]++; 
			}
			std::cout << mapNum[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}

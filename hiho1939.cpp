#include <iostream>

#define MAXN 105

int map[MAXN][MAXN] = {0};

int numOfEdge;
int main() {
	std::cin >> numOfEdge;
	for (int i = 1; i <= numOfEdge; i++) {
		for (int j = 0; j < 2 * i - 1; j++) {
			std::cin >> map[i][j];
		}
	}
	return 0;
}

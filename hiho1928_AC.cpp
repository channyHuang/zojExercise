#include <iostream>

#define MAXN 1005

int leftHeight[MAXN];
int frontHeight[MAXN];

int mymin(int x, int y) {
	return x <= y ? x : y;
}

int main() {
	int totalrow, totalcol;
	std::cin >> totalrow >> totalcol;
	for (int i = 0; i < totalrow; i++) {
		std::cin >> leftHeight[i];
	}
	for (int i = 0; i < totalcol; i++) {
		std::cin >> frontHeight[i];
	}
	int res = 0;
	for (int i = 0; i < totalrow; i++) {
		for (int j = 0; j < totalcol; j++) {
			res += mymin(leftHeight[i], frontHeight[j]);
		}
	}
	std::cout << res;
	return 0;
}

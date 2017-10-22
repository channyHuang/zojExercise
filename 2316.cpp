#include <iostream>
#include <cstring>
#include <string>

#define MAXN 10001

int data[MAXN][MAXN];

int main() {
	int numOfCase, numOfV, numOfE;
	int a, b;
	std::cin >> numOfCase;
	while (numOfCase--) {
		memset(data, 0, sizeof(data));
		std::cin >> numOfV >> numOfE;
		for (int j = 0; j < numOfE; j++) {
			std::cin >> a >> b;
			data[a-1][j] = 1;
			data[b-1][j] = 1;
		}
		int sum = 0;
		for (int i = 0; i < numOfE; i++) {
			for (int j = 0; j < numOfE; j++) {
				for (int k = 0; k < numOfV; k++) 
					sum = sum + data[k][i]*data[k][j];
			}
		}
		std::cout << sum << std::endl;
		if (numOfCase) std::cout << std::endl;
	}
	return 0;
}

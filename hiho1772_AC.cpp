#include <iostream>

#define MAXN 200005

char input[3][MAXN] = {0};

int main() {
	std::cin >> input[0] >> input[1] >> input[2];
	int pos = 0;
	int dis = 0;
	while (input[0][pos] != 0) {
		if (input[0][pos] != input[1][pos]) {
			if (input[0][pos] != input[2][pos]) {
				if (input[1][pos] != input[2][pos]) dis += 2;
				else dis += 1;
			} else dis += 1;
		} else if (input[0][pos] != input[2][pos]) dis += 1;
		//std::cout << pos << " " << dis << std::endl;
		pos++;
	}
	std::cout << dis << std::endl;
	return 0;
}

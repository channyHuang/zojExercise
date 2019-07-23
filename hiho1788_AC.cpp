#include <iostream>

#define MAXN 100005

char input[MAXN];

int main() {
	while (std::cin >> input) {
	int i = 1;
	bool flag = false; 
	while (input[i] != 0) {
		if (input[i] == input[i - 1]) {
			flag = true;
			break;
		}
		i++;
	}
	if (flag) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	}
	return 0;
}

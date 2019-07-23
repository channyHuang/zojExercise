#include <iostream>

#define MAXN 100005

char input[MAXN];

int main() {
	std::cin >> input;
	int i = 1;
	int res = 0;
	while (input[i] != 0) {
		if (input[i] == input[i-1]) {
			res++;
			i += 2;
		}
		else i++;
	}
	std::cout << res << std::endl;
	return 0;
}

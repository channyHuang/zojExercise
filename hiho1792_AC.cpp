#include <iostream>

int main() {
	int n, res = 0;
	std::cin >> n;
	int x = n ^ (n-1);
	while (x) {
		x &= (x-1);
		res++;
	}
	std::cout << res << std::endl;
	return 0;
}

#include <iostream>

int main() {
	long long numOfPC, oneTimePC;
	std::cin >> numOfPC >> oneTimePC;

	long long target = oneTimePC * numOfPC + 1;
	long long res = 1; 

	if (numOfPC == 1) {
		std::cout << "0" << std::endl;
		return 0;
	}

	long long curPC = oneTimePC + 1;
	while (curPC < target) {
		curPC *= (oneTimePC + 1);
		res++;
	}

	std::cout << res << std::endl;
	return 0;
}

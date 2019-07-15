#include <iostream>

int revert(int s) {
	int e = s % 10 * 1000;
	e += s % 100 / 10 * 100;
	e += s % 1000 / 100 * 10;
	e += s % 10000 / 1000 * 1;
	return e;
}

int main() {
	int nStart, nEnd;
	std::cin >> nStart >> nEnd;
	int re = 0;
	for (int nSt = nStart; nSt <= nEnd; nSt++) {
		if (revert(nSt) - nSt >= 1000) re++;
	}
	std::cout << re << std::endl;
}

#include <iostream>

#define MAXN 1000005
int enemy[MAXN] = {0};
int main() {
	int numOfEne, tmp;
	std::cin >> numOfEne;
	int curPos = 0, res = 0;
	while(numOfEne--) {
		std::cin >> tmp;
		enemy[tmp]++;
	}
	for (curPos = 1; curPos <= MAXN; curPos++) {
		if (enemy[curPos] == 0) break;
		res += enemy[curPos];
	}
	std::cout << res << std::endl;
			
	return 0;
}

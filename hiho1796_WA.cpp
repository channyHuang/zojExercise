#include <iostream>

#define MAXN 100005
int num[MAXN] = {0};

int main() {
	int res = 0;
	long long numOfNum, k;
	std::cin >> numOfNum >> k;
	for (int i = 0; i < numOfNum; i++) {
		std::cin >> num[i];
		if ((num[i] << 1) % k == 0) res++;
	}
	if (res == 0) res = -1;
	std::cout << res << std::endl;
	return 0;
}

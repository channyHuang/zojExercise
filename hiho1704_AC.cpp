#include <iostream>

#define MAXN 100005
int num[MAXN] = {0};

int main() {
	int numOfNum;
	std::cin >> numOfNum;
	int sum[MAXN] = {0};
	for (int i = 0; i < numOfNum; i++) {
		std::cin >> num[i];
		if (i == 0) sum[i] = num[i];
		else sum[i] = sum[i-1] + num[i];
	}
	if (sum[numOfNum - 1] <= 0) {
		std::cout << "-1" << std::endl;
		return 0;
	}
	int res = -1;
	for (int i = 0; i < numOfNum; i++) {
		if (num[i] <= 0) continue;
		bool flag = true;
		for (int j = i + 1; j != i; j = (j + 1) % numOfNum) {
			if (j > i) {
				int preSum = 0;
				if (i > 0) preSum = sum[i - 1]; 
				if (sum[j] - preSum <= 0) {
					flag = false;
					break;
				}
			} else {
				int preSum = 0;
				if (i > 0) preSum = sum[i - 1];
				if (sum[numOfNum - 1] - preSum + sum[j] <= 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			res = i + 1;
			break;
		}
	}

	std::cout << res << std::endl;
	return 0;
}

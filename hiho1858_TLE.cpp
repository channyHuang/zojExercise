#include <iostream>
//2 of 1, others are 0

int main() {
	int num, tmp, count1;
	std::cin >> num;
	for (int i = 2; i < num; i++) {
		if (num % i != 0 && num % i != 1) continue;
		bool flag = true;
		tmp = num;
		count1 = 0;
		while (tmp) {
			if (tmp % i == 0) {
				tmp /= i;
				continue;
			} else if (tmp % i == 1) {
				count1++;
				if (count1 > 2) {
					flag = false;
					break;
				}
				tmp /= i;
			} else {
				flag = false;
				break;
			}
		}
		if (flag) std::cout << i << std::endl;
	}
	return 0;
}

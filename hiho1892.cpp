#include <iostream>
#include <string>
#include <cstring>

#define MAXN 100002
#define DEBUG false

int main() {
	char origin[MAXN], target[MAXN];
	int count = 0;
	std::cin >> origin >> target;

	int nCar[26] = {0};
	bool flag = true;
	int len = 0; 
	while(origin[len]) {
		nCar[origin[len] - 'A']++;
		len++;
	}
	int targetLen = 0;
	while(target[targetLen]) {
		int nTmp = target[targetLen] - 'A';
		if (nCar[nTmp] <= 0) {
			flag = false;
			break;
		}
		nCar[nTmp]--;
		targetLen++;
	}

	if (len != targetLen || !flag) {
		std::cout << "-1" << std::endl;
		return 0;
	}

	if (DEBUG) std::cout << "len = " << len << std::endl;

	int notMovePos = len - 1;
	for (int i = len - 1; i >= 0; i--) {
		if (origin[i] == target[notMovePos]) notMovePos--;
		if (notMovePos < 0) break;
	}
	if (DEBUG) std::cout << "notMovePos = " << notMovePos << std::endl;
	if (notMovePos < 0) count = 0;
	else count = notMovePos + 1;

	std::cout << count;
	return 0;
}

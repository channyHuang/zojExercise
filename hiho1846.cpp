#include <iostream>

//A, B, C, AB, AC, BC, ABC
int objs[8] = {0};

int minCost;
void search(int curObj, int curRes, bool flags[3]) {
	if (flags[0] && flags[1] && flags[2]) {
		if (curRes < minCost) minCost = curRes;
		return;
	}
	search(curObj + 1, curRes, flags);	

	curRes += objs[curObj];
	if (curObj < 3) flags[curObj] = true;
	else if (curObj == 3) {
		flags[0] = true;
		flags[1] = true;
	} else if (curObj == 4) {
		flags[0] = true;
		flags[2] = true;
	} else if (curObj == 5) {
		flags[1] = true;
		flags[2] = true;
	} else {
		flags[0] = true;
		flags[1] = true;
		flags[2] = true;
	}
	search(curObj + 1, curRes, flags);
}

int main() {
	int numOfObj;
	int tmpNo;
	char tmpObj[5];
	std::cin >> numOfObj;
	while (numOfObj--) {
		std::cin >> tmpNo >> tmpObj;
		int len = 0;
		while(tmpObj[len] != 0) len++;
		if (len == 1) {
			if (objs[tmpObj[0] - 'A'] > tmpNo) objs[tmpObj[0] - 'A'] = tmpNo;
		} else if (len == 3) {
			if (objs[6] > tmpNo) objs[6] = tmpNo;
		} else {
			if ('A' != tmpObj[0] && 'A' != tmpObj[1]) {
				if (objs[5] > tmpNo) objs[5] = tmpNo;
			} else if ('B' != tmpObj[0] && 'B' != tmpObj[1]) {
				if (objs[4] > tmpNo) objs[4] = tmpNo;	
			} else {
				if (objs[3] > tmpNo) objs[3] = tmpNo;
			}
		}
	}
	if (objs[0] + objs[3] + objs[4] + objs[6] == 0) minCost = -1;
	else if (objs[1] + objs[3] + objs[5] + objs[6] == 0) minCost = -1;
	else if (objs[2] + objs[4] + objs[5] + objs[6] == 0) minCost = -1;
	else {
		bool flags[3] = {false};
		int curRes = 0;
		for (int i = 0; i < 7; i++) {
			minCost += objs[i];
		}
		search(0, curRes, flags);
	}

	std::cout << minCost << std::endl;
	return 0;
}

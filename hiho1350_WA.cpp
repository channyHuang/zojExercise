#include <iostream>
#include <iomanip>

int value[11] = {32, 16, 8, 4, 2, 1, 16, 8, 4, 2, 1};
//int value[11] = {1, 2, 4, 8, 16, 32, 1, 2, 4, 8, 16};
int hour = 0, min = 0;
bool debug = false;

void dfs(int curPos, int numOfHour, int numOfMin) {
	if (debug) {
		std::cout << curPos << " " << numOfHour << " " << numOfMin << std::endl;
	}
	if (numOfMin < 0) return;
	if (curPos >= 6 && (numOfMin > 0 || numOfHour < 0)) return;
	if (curPos == 11) {
		if (numOfHour > 0) return;
		std::cout << std::setw(2) << std::setfill('0') << hour << ":" <<  std::setw(2) << std::setfill('0') << min << std::endl;
		return;
	}
	for (int i = 0; i <= 1; i++) {
		if (curPos < 6) {
			if (i == 1) {
				min += value[curPos];
				if (min > 60) {
					min -= value[curPos];
					continue;
				}
				dfs(curPos + 1, numOfHour, numOfMin  - 1);
				min -= value[curPos];
			}
			else dfs(curPos + 1, numOfHour, numOfMin);
		}
		else {
			if (i == 1) {
				hour += value[curPos];
				if (hour >= 24) {
					hour -= value[curPos];
					continue;
				}
				dfs(curPos + 1, numOfHour - 1, numOfMin);
				hour -= value[curPos];
			}
			else dfs(curPos + 1, numOfHour, numOfMin);
		}
	}
}

int main() {
	int numOfOne;
	std::cin >> numOfOne;
	for (int i = 0; i < 5; i++) {
		if (i > numOfOne) break;
		dfs(0, i, numOfOne - i);
	}
}

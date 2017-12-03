#include <iostream>
#include <iomanip>
int digits[4];
bool used[4] = {0};
int maxHour = -1, maxMin = 0;

void dfs(int curPos, int curTime) {
	if (curPos >= 4) {
		int curHour = curTime / 100;
		int curMin = curTime % 100;
		if (curHour >= 24 || curMin % 100 >= 60) return;
		if (curHour > maxHour || (curHour == maxHour && curMin > maxMin)) {
			maxHour = curHour;
			maxMin = curMin;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (used[i]) continue;
		used[i] = 1;
		dfs(curPos + 1, curTime * 10 + digits[i]);
		used[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		std::cin >> digits[i];
	}
	dfs(0, 0);
	if (maxHour == -1) std::cout << "NOT POSSIBLE" << std::endl;
	else std::cout << std::setw(2) << std::setfill('0') << maxHour << ":" << std::setw(2) << std::setfill('0') << maxMin << std::endl;

	return 0;
}

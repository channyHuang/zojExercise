#include <iostream>

#define MAXN 100005

int times[MAXN] = {0}; //i->i+1
int dis[MAXN] = {0};//0->i
//a <= b
void swap(int &a, int &b) {
	if (a <= b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

int calPos(int r, int c) {
	return r * MAXN + c;
}

int main() {
	int totalStation = 0, totalSearch = 0;
	int totalDis = 0;
	std::cin >> totalStation >> totalSearch;
	for (int i = 0; i < totalStation; i++) {
		std::cin >> times[i];
		totalDis += times[i];
		dis[i + 1] = dis[i] + times[i];
	}
		
	int nStart, nEnd, res = 0;
	while (totalSearch--) {
		std::cin >> nStart >> nEnd;	

		if (nStart == nEnd) {
			std::cout << "0" << std::endl;
			continue;
		}

		swap(nStart, nEnd);

		res = dis[nEnd - 1] - dis[nStart - 1];
		if (res > totalDis - res) res = totalDis - res;

		std::cout << res << std::endl;
	}
	return 0;
}

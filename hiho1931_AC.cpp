#include <iostream>

#define MAXN 100005

int ys[MAXN];

void swap(int a, int b) {
	int tmp = ys[a];
	ys[a] = ys[b];
	ys[b] = tmp;
}

void qsort(int s, int e) {
	if (s >= e) return;
	int cur = s;
	int st = s, end = e;
	while (1) {
		bool flag = false;
		while (end > st && ys[end] >= ys[cur]) end--;
		if (end > st) {
			swap(cur, end);
			cur = end;
			flag = true;
		}
		while (st < end && ys[st] <= ys[cur]) st++;
		if (st < end) {
			swap(cur, st);
			cur = st;
			flag = true;
		}
		if (!flag) break;
	}
	qsort(s, cur - 1);
	qsort(cur + 1, e);
}

void output(int n) {
	for (int i = 0; i < n; i++) std::cout << " " << ys[i];
	std::cout << std::endl;
}

int main() {
	int numOfNode, tmp;
	std::cin >> numOfNode;
	for (int i = 0; i < numOfNode; i++) {
		std::cin >> tmp >> ys[i];		
	}
	qsort(0, numOfNode - 1);
//	output(numOfNode);
	
	long long res = 0;
	int targetPos = numOfNode / 2;
	for (int i = 0; i < targetPos; i++) {
		res += (ys[numOfNode - i - 1] - ys[i]);
	} 
	std::cout << res << std::endl;
	return 0;
}

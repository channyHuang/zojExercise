#include <iostream>

#define MAXN 1000001
#define POWNUM 20

int pow2[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int min(int a, int b) {
	return (a < b ? a : b);
}

void computePow() {
	for (int i = 11; i <= POWNUM; i++) {
		pow2[i] = pow2[i-1] * 2;
	}
}

int findPow(int beginPt, int endPt, int n) {
	if (beginPt == endPt) return pow2[beginPt];
	if (beginPt + 1 == endPt) {
		if (pow2[endPt] <= n) return pow2[endPt];
		else return pow2[beginPt];
	}
	int midPt = (beginPt + endPt) / 2;
	if (pow2[midPt] == n) return n;
	else if (pow2[midPt] <= n) return findPow(midPt, endPt, n);
	else return findPow(beginPt, midPt-1, n);
}

int pre_calc[MAXN][POWNUM];

int main() {
	int numOfCase, numOfNode, numOfPro;
	int left, right;
	computePow();

	//std::cin >> numOfCase;
	//while(numOfCase--) {
		std::cin >> numOfNode;
		for (int i = 0; i < numOfNode; i++) {
			std::cin >> pre_calc[i][1];
			for (int j = 1; j <= POWNUM; j++) {
				int len = pow2[j];
				if (i - len < 0) break;
				pre_calc[i-len+1][len] = min(pre_calc[i-len+1][len/2], pre_calc[i-len/2+1][len/2]);
			}
		}
		std::cin >> numOfPro;
		while(numOfPro--) {
			std::cin >> left >> right;
			left--;
			right--;
			int len = findPow(0, POWNUM, right - left+1);
			int result = min(pre_calc[left][len], pre_calc[right-len+1][len]);
			std::cout << result << std::endl;
		}
	//}
	return 0;
}

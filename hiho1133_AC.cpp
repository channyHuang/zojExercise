#include <iostream>

#define MAXN 1000001

int data[MAXN];
bool debug = false;

int find(int beginPt, int endPt, int k) {
	int midPos = (beginPt + endPt) / 2;
	if (debug) std::cout << midPos << std::endl;
	int beginPos = beginPt, endPos = endPt;
	while (1) {
		while (beginPos < endPos && data[endPos] > data[midPos]) endPos--;
		while (beginPos < endPos && data[beginPos] < data[midPos]) beginPos++;
		if (debug) std::cout << beginPos << " " << endPos << std::endl;
		if (beginPos < endPos) {
			int tmp = data[beginPos];
			data[beginPos] = data[endPos];
			data[endPos] = tmp;

			if (midPos == beginPos) midPos = endPos;
			else if (midPos == endPos) midPos = beginPos;
		}
		else {
			if (debug) std::cout << midPos << std::endl;
			if (midPos == k - 1) return data[midPos];
			else if (midPos > k - 1) return find(beginPt, midPos - 1, k);
			else return find(midPos + 1, endPt, k);
		}
	}

}

int main() {
	int numOfNode, target;
	std::cin >> numOfNode >> target;
	for (int i = 0; i < numOfNode; i++) {
		std::cin >> data[i];
	}
	std::cout << find(0, numOfNode - 1, target) << std::endl;

	return 0;
}

#include <iostream>

#define MAXN 1000001

int data[MAXN];
bool debug = false;

int main() {
	int numOfNode, target;
	std::cin >> numOfNode >> target;
	for (int i = 0; i < numOfNode; i++) {
		std::cin >> data[i];
	}
	int midPos = 0;
	for (; midPos < numOfNode; midPos++) {
		if (data[midPos] == target) break;
	}
	if (midPos == numOfNode) {
	       std::cout << "-1" << std::endl;
	       return 0;
	}

	int beginPos = 0, endPos = numOfNode - 1;
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
		else break;
	}
	std::cout << beginPos + 1 << std::endl;

	return 0;
}

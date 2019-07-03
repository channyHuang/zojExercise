#include <iostream>

#define MAXN 1000002

char inputStr[MAXN];
int maxLen = 1;

//return length, and midPos
int judgeRev(int beginPos, int endPos, int &revMidPos) {
	midPos = -1;
	if (beginPos > endPos) return 0;	
	if (beginPos == endPos) {
		midPos = beginPos;
		return 1;
	}
	int preMidPos = -1, posMidPos = -1;
	int midPos = (beginPos + endPos) / 2;
	int preLen = judgeRev(beginPos, midPos, preMidPos);
	int posLen = judgeRev(midPos + 1, endPos, posMidPos);

	if (preLen != 0 && preMidPos + preLen / 2 == midPos) {
		//even
		for (int x = preLen / 2; preMidPos - x >= beginPos && preMidPos + x + 1 <= endPos; x++) {
			if (inputStr[preMidPos - x] != inputStr[preMidPos + x + 1] break;
		}
		preLen = (x - 1) * 2;
		//odd
		for (int x = preLen / 2; preMidPos - x >= beginPos && preMidPos + x  <= endPos; x++) {
			if (inputStr[preMidPos - x] != inputStr[preMidPos + x + 1]) break;
		}
	}
	if (posLen != 0 && posMidPos - posLen == midPos + 1) {
		for (int x = posLen; posMidPos - x >= beginPos && posMidPos + x <= endPos; x++) {
			if (inputStr[posMidPos - x] != inputStr[posMidPos + x] break;
		}
	}
	
	if (preLen < posLen) return posLen;
	else return preLen;
}

int main() {
	int numOfCase;
	std::cin >> numOfCase;
	while(numOfCase--) {
		memset(inputStr, 0, MAXN);		
		maxLen = 1;

		std::cin >> inputStr;

		int nMidPos = 0;
		while(inputStr[nMidPos] != 0) {
			//even
			for (int x = 1; nMidPos - x >= 0 && inputStr[nMidPos + x] != 0; x++) {
				if (inputStr[nMidPos] != inputStr[]
			//odd

			nMidPos++;
		}

		std::cout << maxLen;
	}
	return 0;
}

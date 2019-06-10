#include <iostream>

#define MAX 5000

int nNum[MAX];

int findTargetNum(int num, int startPos, int endPos) 
{
	if (endPos < startPos) return -1;


	if (nNum[startPos] == num) return startPos;
	if (nNum[endPos] == num) return endPos;
	if (nNum[startPos] > num) return -1;
	if (nNum[endPos] < num) return -1;

	

	int midPos = (startPos + endPos)/2;	

	if (nNum[midPos] > num)	
		return findTargetNum(num, startPos, midPos - 1);
	else if (nNum[midPos] < num)
		return findTargetNum(num, midPos + 1, endPos);
	else return midPos;
}

int main() {
	int nTotalNum, nTmp;
	int nMinu[MAXN];
	std::cin >> nTotalNum;
	for (int i = 0; i < nTotalNum; i++) {
		std::cin >> nTmp;
		int j = i - 1;	
		while(j >= 0 && nNum[j] > nTmp) {
		       	nNum[j + 1] = nNum[j];
			j--;
		}
		nNum[j] = nTmp;	
	}

	if (nTotalNum < 2) return 0;

	int nMaxCount = 0;
	int nCurCount = 2;
	for (int i = 0; i < nTotalNum; i++) 
	{
		for (int j = i + 1; j < nTotalNum; j++) 
		{
			nCurCount = 2;
			int nTarget = nNum[j] + nNum[j] - nNum[i];  
			int nStartPos = j + 1;
			int nEndPos = nTotalNum - 1;
			while (1)
			{
				int res = findTargetNum(nTarget, nStartPos, nEndPos);
				if (res == -1) break;
				nCurCount++;
				nTarget = nNum[res] + nNum[j] - nNum[i];
				nStartPos = res + 1;
			}

			if (nCurCount >= 3 && nCurCount > nMaxCount) nMaxCount = nCurCount;	
		}
	}

	std::cout << nCurCount;

	return 0;
}

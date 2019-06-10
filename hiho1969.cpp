#include <iostream>
#include <cstring>
#include <string>

#define MAX 5000
#define MAXN 1000002

int nNum[MAX];
bool bNum[MAXN];

void qSort(int nStartPos, int nEndPos)
{
	if (nStartPos >= nEndPos) return;

    int start = nStartPos, end = nEndPos;
	int curPos = start;

	bool flag = true;
	while(flag)
	{
		flag = false;
	while(start < curPos && nNum[start] < nNum[curPos]) start++;
	if (start < curPos)
	{
		int tmp = nNum[start];
		nNum[start] = nNum[curPos];
		nNum[curPos] = tmp;
		curPos = start;
		flag = true;
	}
	while(end > curPos && nNum[end] > nNum[curPos]) end--;
	if (end > curPos)
	{
		int tmp = nNum[end];
		nNum[end] = nNum[curPos];
		nNum[curPos] = tmp;
		curPos = end;
		flag = true;
		}
	}

	qSort(nStartPos, curPos);
	qSort(curPos + 1, nEndPos);
}	

#define DEBUG true

int main() {
	int nTotalNum, nTmp;

	memset(nNum, 0, MAX);

	std::cin >> nTotalNum;
	for (int i = 0; i < nTotalNum; i++) {
		std::cin >> nNum[i];
		bNum[nTmp] = true;
	}

	qSort(0, nTotalNum - 1);

	if (DEBUG)
	{
		for (int i = 0; i < nTotalNum; i++) 
			std::cout << " " <<  nNum[i];
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


			while (1)
			{
				if (bNum[nTarget]) 	nCurCount++;
				nTarget = nTarget + nNum[j] - nNum[i];	
			}

			if (nCurCount >= 3 && nCurCount > nMaxCount) nMaxCount = nCurCount;	
		}
	}

	std::cout << nMaxCount;

	return 0;
}

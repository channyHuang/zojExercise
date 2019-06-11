#include <iostream>
#include <cstring>
#include <string>

#define MAX 5000
#define MAXN 1000002

int nNum[MAX];
int bNum[MAXN];

#define DEBUG false

int nTotalNum;

void output()
{
	if (DEBUG)
     {
         for (int i = 0; i < nTotalNum; i++)
             std::cout << " " <<  nNum[i];
     }
}

void qSort(int nStartPos, int nEndPos)
{

	if (nStartPos >= nEndPos) return;

    int start = nStartPos, end = nEndPos;
	int curPos = start;



	bool flag = true;
	while(flag)
	{
		flag = false;
		while(start < curPos && nNum[start] <= nNum[curPos]) start++;
		if (start < curPos)
		{
			int tmp = nNum[start];
			nNum[start] = nNum[curPos];
			nNum[curPos] = tmp;
			curPos = start;
			flag = true;
		}
		while(end > curPos && nNum[end] >= nNum[curPos]) end--;
		if (end > curPos)
		{
			int tmp = nNum[end];
			nNum[end] = nNum[curPos];
			nNum[curPos] = tmp;
			curPos = end;
			flag = true;
		}
	
	}

	if (nStartPos < curPos)
		qSort(nStartPos, curPos);
	if (curPos + 1 < nEndPos) 
		qSort(curPos + 1, nEndPos);
}	



int main() {
	int nTmp;

	memset(nNum, 0, MAX);
	memset(bNum, 0, MAXN);

	std::cin >> nTotalNum;
	int nRepeatNum = 0;
	for (int i = 0; i < nTotalNum; i++)
	{
		std::cin >> nNum[i];
		bNum[nNum[i]]++;
		if (bNum[nNum[i]] >= 3 && bNum[nNum[i]] > nRepeatNum)
			nRepeatNum = bNum[nNum[i]];
	}

	if (nTotalNum < 2) {
		std::cout << "0" << std::endl;
		return 0;
	}

	qSort(0, nTotalNum - 1);


	int nMaxCount = nRepeatNum;
	int nCurCount = 2;
	int nCurStartPos = 0, nCurNextPos = 0;
	for (int i = 0; i < nTotalNum; i++) 
	{

		for (int j = i + 1; j < nTotalNum; j++) 
		{
			if (nMaxCount != 0)
			{
				if (nNum[nCurStartPos] + (nMaxCount - 1) * (nNum[nCurNextPos] - nNum[nCurStartPos]) > nNum[nTotalNum - 1]) break;
			}
			if (nNum[i] - nNum[j] + nNum[i] >= 0 && bNum[nNum[i] - nNum[j] + nNum[i]]) continue; 

			nCurCount = 2;
			int nTarget = nNum[j] + nNum[j] - nNum[i];  


			while (1)
			{
				if (bNum[nTarget]) 	nCurCount++;
				else break;
				nTarget = nTarget + nNum[j] - nNum[i];	
			}

			if (nCurCount >= 3 && nCurCount > nMaxCount) {
				nMaxCount = nCurCount;	
				nCurStartPos = i;
				nCurNextPos = j;
			}
		}
	}

	std::cout << nMaxCount << std::endl;

	return 0;
}

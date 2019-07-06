#include <iostream>
#include <cstring>
#include <string>

#define MAXN 1005

char cInput[MAXN];

int main() {
	int nCase, nLen, nLeft, nStar;
	bool flag = true;
	std::cin >> nCase;
	while(nCase--) {
		memset(cInput, 0, MAXN);
		std::cin >> cInput;
	
		for (nLen = 0; cInput[nLen] != 0; nLen++);

		if (nLen % 2 != 0) {
			std::cout << "NO" << std::endl;
			continue;
		}

		nLeft = 0;
		nStar = 0;
		flag = true;
		for (int i = 0; i < nLen; i++) {
			if (cInput[i] == '*') {
				 nStar++;
			}
			else if (cInput[i] == '(') nLeft++;
			else {
				if (nLeft > 0) nLeft--;
				else if (nStar > 0) nStar--;
				else {
					flag = false;
					break;
				}
			}
		}

		if (nLeft > nStar) flag = false;

		if (flag) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
	return 0;
}

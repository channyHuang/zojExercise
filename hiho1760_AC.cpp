#include <iostream>

#define MAXN 1005

char s[MAXN] = {0}, t[MAXN] = {0};

int main() {
	int numOfCase;
	
	std::cin >> numOfCase;
	while (numOfCase--) {
		std::cin >> s >> t;
		int lenS = 0, lenT = 0;
		while (s[lenS] != 0) lenS++;
		while (t[lenT] != 0) lenT++;
		
		if (lenT < lenS / 2) {
			std::cout << "No" << std::endl;
			continue;
		}
				
			//ABA / BAB
	
			bool flag = true;
			//AB / BA
			int tPos = 0;
			for (int i = 1; i < lenS; i += 2) {
				while (tPos < lenT && t[tPos] != s[i]) tPos++;
				if (tPos >= lenT) {
					flag = false;
					break;
				}
				tPos++;
			}

			if (!flag) {
				flag = true;
				tPos = 0;
				for (int i = 0; i < lenS; i += 2) {
					
					while (tPos < lenT && t[tPos] != s[i]) tPos++;
					//std::cout << i << " " << tPos << " " << lenT << std::endl;
					if (tPos >= lenT) {
						flag = false;	
						break;
					}
					tPos++;
				}
			}
						
			if (!flag) std::cout << "No" << std::endl;
			else std::cout << "Yes" << std::endl;	
		
	}
	return 0;
}

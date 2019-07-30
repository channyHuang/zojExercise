#include <iostream>

#define MAXN 1005

int s[MAXN] = {0}, t[MAXN] = {0};

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
				
		if (lenS % 2) {
			
		} else {
			//AB / BA
			if (t[lenT] != 0) std::cout << "No" << std::endl;
			else if (lenT == lenS) std::cout << "Yes" << std::endl;
			else std::cout << "No" << std::endl; 
		}
	}
	return 0;
}

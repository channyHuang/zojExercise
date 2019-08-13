#include <iostream>
#include <cstring>
#include <string>

#define MAXN 1005

char maps[26];

int main() {
	int numOfCase;
	std::cin >> numOfCase;
	char str[MAXN], dst[MAXN];
	while (numOfCase--) {
		std::cin >> str >> dst;
		memset(maps, 0, sizeof(maps));
		int lenStr = 0;
		bool flag = false;
		while (str[lenStr] != 0) {
			if (dst[lenStr] == 0) break;
			if (maps[str[lenStr] - 'a'] == 0) {
				maps[str[lenStr] - 'a'] = dst[lenStr];
			} else {
				if (maps[str[lenStr] - 'a'] != dst[lenStr]) break;
			}
			lenStr++;
		}
		if (str[lenStr] == 0 && dst[lenStr] == 0) flag = true;
		if (flag) std::cout << "YES" <<  std::endl;
		else std::cout << "NO" << std::endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>

#define MAXN 1001

bool used[MAXN];
int count[4];
std::string str;
int len;

void dfs(int i, int numOfChar) {
	if ( i < 0 ||  i >= len) return;
	if (used[i]) return;
	used[i] = true;
	if (str[i] == 'A') count[0]++;
	else if (str[i] == 'T') count[1]++;
	else if (str[i] == 'C') count[2]++;
	else count[3]++;
	// know first, search last
	dfs(len + i - numOfChar, numOfChar);
	// know last, search first
	if (numOfChar - len + i < numOfChar) dfs(numOfChar - len + i, numOfChar);
}

int main() {
	int numOfCase, numOfChar;
	
	std::cin >> numOfCase;
	while(numOfCase--) {
		std::cin >> str >> numOfChar;
		len = str.length();
		int result = 0;
		memset(used, 0, sizeof(used));

		for (int i = 0; i < numOfChar; i++) {
			if (used[i]) continue;
			for (int j = 0; j < 4; j++) count[j] = 0;
			dfs(i, numOfChar);
			int sum = count[0], maxn = count[0];
			for (int j = 1; j < 4; j++) {
				sum += count[j];
				if (count[j] > maxn) maxn = count[j];
			}
			result += (sum - maxn);
		}

		std::cout << result << std::endl;
	}
	return 0;
}

#include <iostream>

#define MAXN 100005

bool used[MAXN] = {false};
int subSequence[MAXN] = {0};

int main() {
	int len, sublen;
	std::cin >> len >> sublen;
	for (int i = 0; i < sublen; i++) {
		std::cin >> subSequence[i];
		used[subSequence[i]] = true;
	}
	int j = 0;
	for (int i = 1; i <= len; i++) {
		if (used[i]) continue;
		
		while (subSequence[j] < i) {
			std::cout << subSequence[j++] << std::endl;
			if (j >= sublen) break;
		} 
		std::cout << i << std::endl;
	}
	while (j < sublen) {
		std::cout << subSequence[j++] << std::endl;
	}
	return 0;
}
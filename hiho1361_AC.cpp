#include <iostream>
#include <cstring>
#include <string>

#define MAXN 26

bool used[MAXN] = {0};
char table[5][5];

int main() {
	std::string word;
	std::cin >> word;
	int pos = 0;
	used['J' - 'A'] = 1;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 'J') word[i] == 'I';
		int idx = word[i] - 'A';
		if (used[idx]) continue;
		used[idx] = 1;
		table[pos / 5][pos % 5] = word[i];
		pos++;	
	}
	for (int i = 0; i < MAXN; i++) {
		if (used[i]) continue;
		table[pos / 5][pos % 5] = i + 'A';
		pos++;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}

 
#include <iostream>
#include <vector>
#include <algorithm>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>

std::<vector> hashTable[50007];
std::string hashString[50007];

int change(char c) {
	if (c == 'Q' || c == 'Z' || c == 'q' || c == 'z') return 0;
	if (c >= 'A' && c < 'Q') return (c - 'A')%3+2;
	else if (c > 'Q' && c < 'Z') return (c - 'A' - 1)%3+2;
	else if (c >= 'a' && c < 'q') return (c-'a')%3+2;
	else return (c - 'a' - 1)%3+2;
}

bool cmp(std::string a, std::string b) {
	int lena = a.length(), lenb = b.length();
	if (a != b) return false; 
	for (int i = 0; i < lena; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	std::string str, hashCode;
	long hashNum;
	while (1) {
		std::cin >> str;
		if (str[0] == '#') break;
		hashNum = 0;
		int len = str.length();
		hashCode = str;
		for (int i = 0; i < len; i++) {
			hashCode[i] = change(str[i]);
			hashNum = hashNum * 131 + hashCode[i];
		}
		hashNum %= 50007;
		while(hashTable[hashNum].size() != 0) {
			if (cmp(hashString[hashNum], hashCode) == false) 
				hashNum++;
			else break;
		}
		hashTable[hashNum].push_back(str);
		hashString[hashNum] = hashCode;
	}
	while(std::cin >> str) {
		int len = str.length();
		for (int i = 0; i < len; i++) {
			hashNum = hashNum * 131 + change(str[i]);
		}
		hashNum %= 50007;
		while (hashTable[hashNum].size() != 0 && hashString[hashNum] != str) hashNum++;
		if (hashTable[hashNum].size() != 0) std::cout << "NONE" << std::endl;
		else {
			std::sort(hashTable[hashNum].begin(), hashTable[hashNum].end());
			for (int i = 0; i < hashTable[hashNum].length(); i++) {
				std::cout << hashTable[hashNum][i];
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
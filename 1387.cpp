//Memory
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

char* originCode[26] = {".-", "-...", "-.-.", "-..", 
	".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
	"--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--.."};

struct Word {
	char wordCode[100];
	int len;
};
std::vector <Word> words; 
int numOfWord;
long count;

bool sameStr(std::string code, int beginPos, int codeLen) {
	if (codeLen <= 0) {
		count++;
		return true;
	}
	int i, j;
	for (i = 0; i < numOfWord; i++) {
		if (codeLen < words[i].len) continue;
		for (j = 0; j < words[i].len; j++) {
			if (code[beginPos + j] != words[i].wordCode[j]) break;
		}
		if (j == words[i].len) {
			sameStr(code, beginPos + words[i].len, codeLen - words[i].len);
		}
	}
	return false;
}

void outputWord() {
	for (int i = 0; i < numOfWord; i++) {
		std::cout << i << ":" << words[i].wordCode << ",len=" << words[i].len << std::endl;
	}		
}

int main() {
	int numOfCase;
	std::string code;
	std::string originStr;
	std::cin >> numOfCase;
	while (numOfCase--) {
		std::cin >> code;	
		std::cin >> numOfWord;
		for (int i = 0; i < numOfWord; i++) {
			Word word;
			word.wordCode[0] = '\0';
			std::cin >> originStr;
			int len = originStr.length();
			for (int j = 0; j < len; j++) {
				std::strcat(word.wordCode, originCode[originStr[j] - 'A']);
			}
			
			word.len = std::strlen(word.wordCode);
			words.push_back(word);
		}
		//outputWord();
		
		count = 0;
		sameStr(code, 0, code.length());
		
		std::cout << count << std::endl;
	}
	return 0;
}
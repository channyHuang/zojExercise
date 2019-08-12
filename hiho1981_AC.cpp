#include <iostream>

class Node {
public:
	char ch;
	Node *children[26];
	int topicIndex;
	Node (char _ch = ' ') {
		ch = _ch;
		for (int i = 0; i < 26; i++) children[i] = nullptr;
		topicIndex = 0;
	}
};

class Topic {
public:
	int numOfWord;
	int score;
	Topic() {
		numOfWord = 0;
		score = 0;
	}
};

Node *root = new Node();
#define WORDLEN 25
Topic topics[15];

void addWord(char word[WORDLEN], int idx) {
	int i = 0;
	Node *curNode = root;
	while (word[i] != '\0') {
		if (curNode->children[word[i] - 'a'] == nullptr) 
			curNode->children[word[i] - 'a'] = new Node(word[i]);
		curNode = curNode->children[word[i] - 'a'];
		i++;
	}
	curNode->topicIndex = idx;
}

bool check(char word[WORDLEN]) {
	int i = 0; 
	Node *curNode = root;
	while (word[i] != '\0') {
		if (curNode->children[word[i] - 'a'] == nullptr) return false;
		curNode = curNode->children[word[i] - 'a'];
		i++;
	}
	if (word[i] != '\0') return false;
	if (curNode->topicIndex == 0) return false;
	topics[curNode->topicIndex - 1].score++;
	return true;
}

int main() {
	int numOfTopic;
	char word[WORDLEN];
	std::cin >> numOfTopic;
	for (int i = 0; i < numOfTopic; i++) {
		std::cin >> topics[i].numOfWord;
	}
	for (int i = 0; i < numOfTopic; i++) {
		for (int j = 0; j < topics[i].numOfWord; j++) {
			std::cin >> word;
			addWord(word, i + 1);
		}
	}
	while (std::cin >> word) {
		check(word);
	}
	for (int i = 0; i < numOfTopic; i++) std::cout << topics[i].score << std::endl;
	return 0;
}
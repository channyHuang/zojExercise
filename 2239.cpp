#include <iostream>

class Node {
public:
	int num;
	Node *pre, *next;
	Node () {
		num = 0;
		pre = NULL;
		next = NULL;
	}
	Node (int n) {
		num = n;
		pre = NULL;
		next = NULL;
	}
};

void deleteNode(Node *node) {
	node->next->pre = node->pre;
	node->pre->next = node->next;
	delete node;
	node = NULL;
}

void output(Node *node) {
	std::cout << node->num << " ";
	Node *curNode = node->next;
	while (curNode->num != node->num) {
		std::cout << curNode->num << " ";
		curNode = curNode->next;
	}
	std::cout << std::endl;
}

int main() {
	char x, y, z;
	int bit, num;
	while(1) {
		std::cin >> x >> y >> z >> bit;
		num = (x-'0') * 10 + y-'0';
		if (num == 0) break;
		while (bit--) num *= 10;

		if (num <= 2) {
			std::cout << "1" << std::endl;
			continue;	
		}

		int curNum = 0;
		for (int i = 2; i <= num; i++) {
			curNum = (curNum + 2) % i;
		}

		std::cout << curNum + 1  << std::endl;
	}

	return 0;
}

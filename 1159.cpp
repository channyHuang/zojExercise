//Memory Limit Exceeded
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class Node {
public:
	Node* parent;
	Node* children[10];
	int num;
	int count;
	
	Node () {
		parent = NULL;
		count = 1;
		num = -1;
		for (int i = 0; i < 10; i++) children[i] = NULL;
	}
	
	Node (int number) {
		parent = NULL;
		count = 1;
		num = number;
		for (int i = 0; i < 10; i++) children[i] = NULL;
	}
};

int main() {
	int numOfCase, numOfNumber, len, num, resultLen;
	int number[8], pos;
	std::string str;
	std::vector<Node *> nodes;
	std::cin >> numOfCase;
	while (numOfCase--) {
		Node *root = new Node();
		nodes.clear();
		std::cin >> numOfNumber;
		while (numOfNumber--) {
			Node *currentNode = root;
			std::cin >> str;
			len = str.length();
			pos = 0;
			for (int i = 0; i < len; i++) {
				if (str[i] == '-') continue;
				else if (str[i] >= '0' && str[i] <= '9') {
					num = str[i] - '0';
				}
				else {
					if (str[i] > 'Q') str[i] -= 1;
					num = (str[i] - 'A')/ 3 + 2;					
				}
				pos++;
				if (currentNode->children[num] == NULL) {
					currentNode->children[num] = new Node(num);
					currentNode->children[num]->parent = currentNode;
				}	
				else {
					if (pos == 7) {
						if (currentNode->children[num]->count == 1) nodes.push_back(currentNode->children[num]);
						currentNode->children[num]->count++;
					}
				}
				currentNode = currentNode->children[num];
				
			}
			/*while (currentNode != NULL) {
				std::cout << currentNode->num;
				currentNode = currentNode->parent;
			}
			std::cout << " End..." << std::endl;*/
		}
		resultLen = nodes.size();
		for (int i = 0; i < resultLen; i++) {
			int j = 7;
			number[j--] = nodes[i]->count;
			while (nodes[i]->num != -1) {
				number[j--] = nodes[i]->num;
				nodes[i] = nodes[i]->parent;
			}
			while (j < 6) {
				std::cout << number[++j];
				if (j == 2) std::cout << "-";
			}
			std::cout << " " << number[7] << std::endl;
		}
		if (numOfCase) std::cout << std::endl;
	}
}
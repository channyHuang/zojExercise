#include <iostream>
#include <cstring>
#include <string>

class Node {
	public:
		int pri;
		std::string name;
		Node *leftChild, *rightChild;
		Node *parent;
		int level;

	Node() {
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
		level = 0;
	}
	Node(int p, std::string n) {
		pri = p;
		name = n;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
		level = 0;
	}
};

void split(std::string str, std::string &s, int &n) {
	int len = str.length();
	int i = 0;
	while (str[i] != '/') i++;
	s = str.substr(0, i);
	n = 0;
	i++;
	while (i < len) {
		n = n * 10 + str[i] - '0';
		i++;
	}
}

void Output(Node *root) {
	if (root == NULL) return;
	std::cout << "(";
	if (root->leftChild != NULL) Output(root->leftChild);
	std::cout << root->name << "/" << root->pri;
	if (root->rightChild != NULL) Output(root->rightChild);
	std::cout << ")";
}

int main() {
	int numOfNode;
	std::string str;
	while (1) {
		std::cin >> numOfNode;
		std::cout << numOfNode << std::endl;
		if (numOfNode == 0) break;
		Node *root = NULL, *curNode = NULL;
		for (int i = 0; i < numOfNode; i++) {
			std::cin >> str;
			Node *node = new Node();
			split(str, node->name, node->pri);
			if (root == NULL) {
				root = node;
				continue;
			}	
			curNode = root;		
			while(curNode->pri > node->pri && curNode->rightChild != NULL) {
				curNode = curNode->rightChild;
			}
			if (curNode->pri > node->pri) {
				curNode->rightChild = node;
				node->parent = curNode;
			}
			else {
				node->leftChild = curNode;
				if (curNode->parent != NULL) {
					curNode->parent->rightChild = node;
					node->parent = curNode->parent;
				}
				else {
					root = node;
				}
				curNode->parent = node;
			}
		}
		//Output
		Output(root);
	}
	return 0;
}

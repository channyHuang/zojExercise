#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

int numOfCase;

class Node {
	public:
		std::string name;
		int size;
		std::vector<Node*> children;
		Node *parent;

		Node() {
			size = 0;
			children.clear();
			parent = NULL;
		}

		Node(std::string inputName, int inputSize) {
			name = inputName;
			size = inputSize;
			children.clear();
			parent = NULL;
		}
};

bool haveSub[11];
void printNode(Node *node, int level) {
	for (int i = 0; i < level; i++) {
		if (i == 0) std::cout << " ";
		else if (haveSub[i]) std::cout << "|";
		else std::cout << " ";
		std::cout << "       ";
	}
	std::cout << "|_" << node->name << "[" << node->size << "]" << std::endl;
	for (int i = 0; i < node->children.size(); i++) {
		if (i < node->children.size() - 1) haveSub[level+1] = true;
		else haveSub[level+1] = false;
		printNode(node->children[i], level+1);
	}
}

void output(std::vector<Node *> nodes) {
	memset(haveSub, 0, sizeof(haveSub));
	for (int i = 0; i < nodes.size(); i++) {
		printNode(nodes[i], 0);
	}
}

int main() {
	std::string name, str;
	int size;
	std::vector<Node *> nodes;
	std::queue<Node *> folders;
	
	while(std::cin >> name) { //every top folder or file
		//if (name[0] == 'C') break;
		std::cin >> size;
		Node *root = new Node(name, size);
		nodes.push_back(root);
		folders.push(root);

		while(!folders.empty()) {
			Node *curNode = folders.front();
			folders.pop();

			while (1) {
				std::cin >> str;
				if (str[0] == '(') name = str.substr(1, str.length()-1);
				else name = str;
				if (name[0] == ')') break;
				std::cin >> size;
				Node *node = new Node(name, size);
				curNode->children.push_back(node);
				if (name[0] == '*') folders.push(node);
			}
		}
	}

	output(nodes);
	return 0;
}

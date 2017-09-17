#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

#define MAXN 100

class Node {
public:
	Node *parent, *leftChild, *rightChild;
	char letter;
	int width, height;
	int numOfLetter;
	char subLetter[3];
	
	Node() {
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
		width = 0;
		height = 0;
		numOfLetter = 0;
	}
	
	Node(char c) {
		Node();
		
		letter = c;
		
		if (c != '-' && c != '|') {
			width = 2;
			height = 2;
		}
		subLetter[0] = c;
		subLetter[1] = c;
	}
};

Node* buildTree(std::string str) {
	int len = str.length();
	Node *root = new Node(str[0]);
	Node *currentNode = root;
	std::cout << "str=" << str << ", len=" << len << std::endl;
	for (int j = 1; j < len; j++) {
		Node* child = new Node(str[j]);
		std::cout << "build child:" << child->letter << ", currentNode = " << currentNode->letter << std::endl;
		child->parent = currentNode;
		if (currentNode->leftChild == NULL) {
			currentNode->leftChild = child;
		}
		else if (currentNode->rightChild == NULL) {
			currentNode->rightChild = child;
		}
		if (child->letter == '-' || child->letter == '|') {
			currentNode = child;
		}
		else {
			currentNode->numOfLetter++;
			while (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {
				if (currentNode->letter == '-') {
					currentNode->width = std::max(currentNode->leftChild->width, currentNode->rightChild->width);
					currentNode->height = currentNode->leftChild->height + currentNode->rightChild->height;
				}
				else {
					currentNode->width = currentNode->leftChild->width + currentNode->rightChild->width;
					currentNode->height = std::max(currentNode->leftChild->height, currentNode->rightChild->height);
				}
				std::cout << "currentNode=" << currentNode->letter << ", parent=" << currentNode->parent->letter << std::endl;
				std::cout << "subLetter=" << currentNode->leftChild->subLetter[0] << " " << currentNode->subLetter[0] << std::endl;
				currentNode->subLetter[0] = currentNode->leftChild->subLetter[0];		
				std::cout << "subLetter=" << currentNode->rightChild->subLetter[0] << " " << currentNode->subLetter[1] << std::endl;				
				currentNode->subLetter[1] = currentNode->rightChild->subLetter[0];
				
				std::cout << "currentNode=" ;//<< currentNode->letter;	
				if (currentNode->parent == NULL) break;
				std::cout << "currentNode=" << currentNode->letter;	
				currentNode = currentNode->parent;
				std::cout << "currentNode=" << currentNode->letter;				
			}
		}
		std::cout << "j=" << j << std::endl;
	}
	return root;
}

char result[MAXN][MAXN];

void drawRect(char c, int beginRow, int beginCol, int height, int width) {
	result[beginRow][beginCol] = c;
	result[beginRow + height][beginCol] = '*';
	result[beginRow][beginCol+width] = '*';
	result[beginRow+height][beginCol+width] = '*';
	for (int i = beginRow+1; i < beginRow+height; i++) result[i][beginCol] = '|';
	for (int j = beginCol+1; j < beginCol + width; j++) result[beginRow][j] = '-';
}

void output(Node *root, int beginRow, int beginCol) {
	drawRect(root->subLetter[0], beginRow, beginCol, root->leftChild->height, root->leftChild->width);
	if (root->letter == '-') {
		drawRect(root->subLetter[1], beginRow+root->leftChild->height, beginCol, root->rightChild->height, root->rightChild->width);
	}
	else if (root->letter == '|') {		
		drawRect(root->subLetter[1], beginRow, beginCol+root->leftChild->width, root->rightChild->height, root->rightChild->width);
	}
}

int main() {
	int numOfCase;
	std::string str;
	std::cin >> numOfCase;	
	for (int i = 1; i <= numOfCase; i++) {
		std::cin >> str;
		std::cout << "input string:" << str << std::endl;
		Node *root = buildTree(str);
		
		output(root, 0, 0);
	}
}	
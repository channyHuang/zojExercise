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
	
	Node() {
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
		width = 0;
		height = 0;
	}
	
	Node(char c) {
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
		width = 0;
		height = 0;
		
		letter = c;
		
		if (c != '-' && c != '|') {
			width = 2;
			height = 2;
		}
	}
};

Node* buildTree(std::string str) {
	int len = str.length();
	Node *root = new Node(str[0]);
	Node *currentNode = root;
	for (int j = 1; j < len; j++) {
		Node* child = new Node(str[j]);
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
			while (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {		
				if (currentNode->letter == '-') {
					currentNode->width = std::max(currentNode->leftChild->width, currentNode->rightChild->width);
					currentNode->height = currentNode->leftChild->height + currentNode->rightChild->height;
				}
				else {
					currentNode->width = currentNode->leftChild->width + currentNode->rightChild->width;
					currentNode->height = std::max(currentNode->leftChild->height, currentNode->rightChild->height);
				}

				if (currentNode->parent == NULL) break;
				currentNode = currentNode->parent;
			}
		}
	}
	while (currentNode->parent != NULL) {
		if (currentNode->letter == '-') {
			currentNode->width = std::max(currentNode->leftChild->width, currentNode->rightChild->width);
			currentNode->height = currentNode->leftChild->height + currentNode->rightChild->height;
		}
		else {
			currentNode->width = currentNode->leftChild->width + currentNode->rightChild->width;
			currentNode->height = std::max(currentNode->leftChild->height, currentNode->rightChild->height);
		}
		currentNode = currentNode->parent;
	}
	return root;
}

char result[MAXN][MAXN];

void drawRect(char c, int beginRow, int beginCol, int width, int height) {
	result[beginRow][beginCol] = c;
	if (result[beginRow + height][beginCol] > 'Z' || result[beginRow + height][beginCol] < 'A') result[beginRow + height][beginCol] = '*';
	if (result[beginRow][beginCol+width] > 'Z' || result[beginRow][beginCol+width] < 'A') result[beginRow][beginCol+width] = '*';
	if (result[beginRow+height][beginCol+width] > 'Z' || result[beginRow+height][beginCol+width] < 'A') result[beginRow+height][beginCol+width] = '*';
	for (int i = beginRow+1; i < beginRow+height; i++) {
		if (result[i][beginCol] > 'Z' || result[i][beginCol] < 'A' && result[i][beginCol] != '*') result[i][beginCol] = '|';
		if (result[i][beginCol + width] > 'Z' || result[i][beginCol + width] < 'A' && result[i][beginCol + width] != '*') result[i][beginCol + width] = '|';
	}
	for (int j = beginCol+1; j < beginCol + width; j++) {
		if (result[beginRow][j] > 'Z' || result[beginRow][j] < 'A' && result[beginRow][j] != '*') result[beginRow][j] = '-';
		if (result[beginRow + height][j] > 'Z' || result[beginRow + height][j] < 'A' && result[beginRow + height][j] != '*') result[beginRow + height][j] = '-';
	}
}

void output(Node *root, int beginRow, int beginCol) {
	if (root->letter == '|') {
		root->leftChild->height = root->height;
		root->rightChild->height = root->height;
		int totalWidth = root->leftChild->width + root->rightChild->width;
		if (totalWidth != root->width) {
			root->rightChild->width = (int)(root->width * root->rightChild->width * 1.0 / totalWidth);
			root->leftChild->width = root->width - root->rightChild->width;
		}
		output(root->rightChild, beginRow, beginCol + root->leftChild->width);
		output(root->leftChild, beginRow, beginCol);
	}
	else if (root->letter == '-') {
		root->leftChild->width = root->width;
		root->rightChild->width = root->width;	
		int totalHeight = root->leftChild->height + root->rightChild->height;
		if (totalHeight != root->height) {
			root->rightChild->height = (int)(root->height * root->rightChild->height * 1.0 / totalHeight);
			root->leftChild->height = root->height - root->rightChild->height;
		}
		output(root->rightChild, beginRow + root->leftChild->height, beginCol);
		output(root->leftChild, beginRow, beginCol);
	}
	else {
		drawRect(root->letter, beginRow, beginCol, root->width, root->height);
	}
	
}

int main() {
	int numOfCase;
	std::string str;
	std::cin >> numOfCase;	
	for (int i = 1; i <= numOfCase; i++) {
		std::cin >> str;
		Node *root = buildTree(str);

		memset(result, ' ', sizeof(result));
		output(root, 0, 0);
		std::cout << i << std::endl;
		for (int i = 0; i <= root->height; i++) {
			for (int j = 0; j <= root->width; j++) {
				std::cout << result[i][j];
			}
			std::cout << std::endl;
		}
	}
}	
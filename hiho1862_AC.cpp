#include <iostream>

#define MAXN 105

//1、6、4、3、2、5
class Node {
public:
	int left, right, up, down, front, back;
};

void left(Node &node) {
	int tmpLeft = node.left;
	int tmpRight = node.right;
	node.left = node.up;
	node.right = node.down;
	node.up = tmpRight;
	node.down = tmpLeft;
}

void right(Node &node) {
	int tmpLeft = node.left;
	int tmpRight = node.right;
	node.left = node.down;
	node.right = node.up;
	node.up = tmpLeft;
	node.down = tmpRight;
}

void front(Node &node) {
	int tmpFront = node.front;
	int tmpBack = node.back;
	node.front = node.up;
	node.back = node.down;
	node.up = tmpBack;
	node.down = tmpFront;
}

void back(Node &node) {
	int tmpFront = node.front;
	int tmpBack = node.back;
	node.front = node.down;
	node.back = node.up;
	node.up = tmpFront;
	node.down = tmpBack;
}

int main() {
	Node node;
	node.left = 4;
	node.right = 3;
	node.up = 1;
	node.down = 6;
	node.front = 2;
	node.back = 5;
	char command[MAXN] = {0};
	std::cin >> command;
	int i = 0;
	while (command[i] != 0) {
		switch(command[i]) {
		case 'F':
			front(node);
			break;
		case 'B':
			back(node);
			break;
		case 'L':
			left(node);
			break;
		case 'R':
			right(node);
			break;
		default:
			break;
		}
		i++;	
	}
	std::cout << node.up << std::endl;
	std::cout << node.down << std::endl;
	std::cout << node.left << std::endl;
	std::cout << node.right << std::endl;
	std::cout << node.front << std::endl;
	std::cout << node.back << std::endl;

	return 0;
}

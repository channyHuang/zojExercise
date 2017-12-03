#include <iostream>
#include <vector>

#define MAXN 100001

class Node {
	public:
		int index;
		int x, y;

		Node() {}
};

std::vector<Node *> nodes;

int main() {
	int numOfNode;
	std::cin >> numOfNode;
	for (int i = 0; i < numOfNode; i++) {
		Node *node = new Node();
		nodes.push_back(node);
		std::cin >> nodes[i]->x >> nodes[i]->y;
	}
	return 0;
}

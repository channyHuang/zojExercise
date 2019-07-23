#include <iostream>

#define MAXN 100005

class Node {
public:
	int left, right;
	int parent;
	int realPar;
	Node() {
		left = -1;
		right = -1;
		parent = -1;
		realPar = -1;
	}
};

Node nodes[MAXN];

void check(int no) {
	if (no == -1) return;
	if (nodes[no].left != -1) {
		nodes[nodes[no].left].realPar = nodes[no].realPar;
		check(nodes[no].left);
	}
	if (nodes[no].right != -1) check(nodes[no].right);
}

int main() {
	int numOfNode;
	std::cin >> numOfNode;

	for (int i = 1; i <= numOfNode; i++) {
		std::cin >> nodes[i].left >> nodes[i].right;
		nodes[nodes[i].left].parent = i;
		nodes[nodes[i].right].parent = i;
		if (nodes[i].right != -1) {
			nodes[nodes[i].right].realPar = i;
		}
	}
	check(1);
	for (int i = 2; i <= numOfNode; i++) {
		std::cout << nodes[i].realPar << std::endl;
	}
	return 0;
}

#include <iostream>

#define MAXN 1005

class Node {
public:
	int no;
	char ch;
	int parent;
	bool isLeaf;
	Node(int _no = 0, char _ch = ' ', int _parent = 0) {
		no = _no;
		ch = _ch;
		parent = _parent;
		isLeaf = true;
	}
};

Node nodes[MAXN];

int check(int a, int b) {
	int oa = a, ob = b;
	while (a != 0 && b != 0) {
		if (nodes[a].ch < nodes[b].ch) return oa;
		else if (nodes[a].ch > nodes[b].ch) return ob;
		else {
			a = nodes[a].parent;
			b = nodes[b].parent;
		}
	}
	if (a == 0) return oa;
	else return ob;
}

int main() {
	int numOfNode;
	std::cin >> numOfNode;
	for (int i = 1; i <= numOfNode; i++) {
		std::cin >> nodes[i].ch >> nodes[i].parent;
		nodes[nodes[i].parent].isLeaf = false;
	}
	int targetPos = 0;
	for (int i = 1; i <= numOfNode; i++) {
		if (!nodes[i].isLeaf) continue;
		if (targetPos == 0) {
			targetPos = i;
			continue;
		}
		targetPos = check(i, targetPos);		
	}

	while (targetPos != 0) {
		std::cout << nodes[targetPos].ch;
		targetPos = nodes[targetPos].parent;
	}
	std::cout << std::endl;
	return 0;
}

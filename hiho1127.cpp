#include <iostream>

#define MAXN 1005

class Index {
public:
	int index;
	Index *next;
	Index(int _idx) {
		index = _idx;
		next = nullptr;
	}
};

class Node {
public:
	int numOfChildren;
	Index *children;
	bool flag;
	Node() {
		flag = false;
		children = nullptr;
		numOfChildren = 0;
	}
};

char edges[MAXN][MAXN] = {0};

Node nodes[MAXN];

void addNode(int a, int b) {
	nodes[a].numOfChildren++;
	if (nodes[a].children == nullptr) nodes[a].children = new Index(b);
	else {
		Index *curIdx = nodes[a].children;
		while (curIdx->next != nullptr) curIdx = curIdx->next;
		curIdx->next = new Index(b);
	}

	edges[a][b] = -1;
}

int findPath(int st, int pathNode[MAXN], int pathLen) {
	int res = 0;
	bool flag = true;
	Index *idx = nodes[st].children;
	while (idx != nullptr) {
		if (nodes[idx->index].flag == nodes[st].flag) {
			idx = idx->next;
			continue;
		}
		pathNode[pathLen] = idx->index;
		int resTmp = findPath(idx->index, pathNode, pathLen + 1);
		if (res < resTmp) res = resTmp;
		flag = false;
	}
	if (flag) {
		if (pathLen % 2 == 0) return 0;
		for (int i = 0; i < pathLen; i++) {
			nodes[pathNode[i]].flag = !nodes[pathNode[i]].flag;
		}
		return pathLen;
	}
	return res;
}

int main() {
	int numOfNode, numOfEdge;
	int a, b;
	std::cin >> numOfNode >> numOfEdge;
	for (int i = 0; i < numOfEdge; i++) {
		std::cin >> a >> b;
		addNode(a, b);
		addNode(b, a);
	}

	int pathNode[MAXN] = {0};
	int res = 0;
	for (int i = 1; i <= numOfNode; i++) {
		if (nodes[i].flag) continue;
		int resTmp = findPath(i, pathNode, 0);
		if (resTmp > res) res = resTmp;
	}

	std::cout << res / 2 << std::endl;

	std::cout << numOfNode - res / 2 << std::endl;
	return 0;
}

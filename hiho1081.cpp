#include <iostream>
#include <queue>

#define MAXN 1001

class Node {
	public:
		int index;
		int totalCost;
		int children[MAXN];
		int cost[MAXN];
		int numOfChild;
		Node *pre, *next;
		bool visited;

		Node() {}
		Node(int idx) {
			index = idx;
			children = NULL;
			pre = NULL;
			next = NULL;
			visited = false;
		}
};

Node *nodes[MAXN];

int main() {
	int numOfNode, numOfEdge, startNum, endNum;
	int a, b, tmp;
	std::cin >> numOfNode >> numOfEdge >> startNum >> endNum;
	while (numOfEdge--) {
		std::cin >> a >> b >> tmp;
		if (nodes[a] == NULL) {
			nodes[a] = new Node(a);
		}
		if (nodes[b] == NULL) {
			nodes[b] = new Node(b);
		}
		nodes[a]->children[nodes[a]->numOfChild] = b;
		nodes[a]->cost[nodes[a]->numOfChild++] = tmp;
		nodes[b]->children[nodes[b]->numOfChild] = a;
		nodes[b]->cost[nodes[b]->numOfChild++] = tmp;
	}
	nodes[startNum]->visited = true;
	std::queue<int> queues;
	queues.push(startNum);
	while (!queues.isempty()) {
		startNum = queues.pop();
		for (int i = 0; i < nodes[startNum]->numOfChild; i++) {
			int num = nodes[startNum]->children[i];
			if (nodes[num]->visited) continue;
			nodes[num]->cost 
			queues.push(num);
		}
	}

	return 0;
}

#include <iostream>
#include <queue>

#define MAXN 10001

class Node {
public:
	int index;
	std::vector<int> children;
	std::vector<int> cost;
	int numOfChild;

	Node() {}
	Node(int idx) {
		index = idx;
		numOfChild = 0;
	}
};

Node *nodes[MAXN];
bool used[MAXN];
int numOfNode, numOfEdge, maxEdge, target;

void initUsed() {
	for (int i = 0; i < numOfNode; i++) used[i] = false;
}

bool pass(int result) {
	initUsed();
	std::queue<int> nextIdx;
	nextIdx.push(1);
	while (nextIdx.empty() == false) {
		int nextIndex = nextIdx.front();
		nextIdx.pop();
		for (int i = 0; i < nodes[nextIndex]->numOfChild; i++) {
			int idx = nodes[nextIndex]->children[i];
			if (nodes[nextIndex]->cost[i] > result) continue;
			if (used[idx] == false) {
				if (idx == target) return true;
				used[idx] = true;
				nextIdx.push(idx);
			}
		}
	}
	return false;
}

int findResult(int begin, int end) {
	if (begin == end) return begin;
	if (begin + 1 == end) {
		if (pass(begin)) return begin;
		else return end;
	}
	int mid = (begin + end) / 2;
	if (pass(mid)) findResult(begin, mid);
        else	findResult(mid + 1, end);
}

int main() {
	int u, v, w;
	std::cin >> numOfNode >> numOfEdge >> maxEdge >> target;
	for (int i = 0; i < numOfEdge; i++) {
		std::cin >> u >> v >> w;
		if (nodes[u] == NULL) nodes[u] = new Node(u);
		if (nodes[v] == NULL) nodes[v] = new Node(v);
		nodes[u]->children.push_back(v);
		nodes[u]->cost.push_back(w);
		nodes[u]->numOfChild++;
		nodes[v]->children.push_back(u);
		nodes[v]->cost.push_back(w);
		nodes[v]->numOfChild++;
	}

	std::cout << findResult(1, 1000000) << std::endl;
	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

class Node {
	public:
		int a, b;
		int cost;
	Node() {}
	Node(int a, int b) {
		this->a = a;
		this->b = b;
	}
	Node(int a, int b, int cost) {
		this->a = a;
		this->b = b;
		this->cost = cost;
	}
};

#define MAXN 101
int pri[MAXN], pre[MAXN];
std::vector<Node *> nodes;

int findParent(int a) {
	while(pre[a] != -1) a = pre[a];
	return a;
}

int cmp(Node *a, Node *b) {
	return a->cost <= b->cost;
}

int findTree(int numOfNode) {
	int result = 0;
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < nodes.size(); i++) {
		int prea = findParent(nodes[i]->a);
		int preb = findParent(nodes[i]->b);
		if (prea == -1) {
			pre[nodes[i]->a] = preb;
		}
		else if (preb == -1) {
			pre[nodes[i]->b] = prea;
		}
		else if (prea != preb) {
			pre[nodes[i]->b] = prea;
		}
		else continue;
		result += nodes[i]->cost;
	}
	return result;
}

int main() {	
	int numOfCase, numOfNode, pub;
	std::cin >> numOfCase;
	while(numOfCase--) {
		std::cin >> numOfNode;
		for (int i = 0; i < numOfNode; i++) std::cin >> pri[i];
		nodes.clear();
		for (int i = 0; i < numOfNode; i++) {
			for (int j = 0; j < numOfNode; j++) {
				std::cin >> pub;
				if (i < j) {
					Node *node = new Node(i, j, pub);
					node->cost += pri[i];
					node->cost += pri[j];
					nodes.push_back(node);
				}
			}
		}		
		std::sort(nodes.begin(), nodes.end(), cmp);

		int result = findTree(numOfNode);
		std::cout << result << std::endl;
	}
	return 0;
}

#include <iostream>

int numOfNode;

#define MAXN 1005

class NodeNo {
public:
	int no;
	NodeNo *next;
	NodeNo(int _no) {
		no = _no;
		next = nullptr;
	}
};

class Node {
public:
	int no;
	int numOfNeighbor;
	NodeNo *neighbor;
	int step;
	Node(int _no = 0) {
		no = _no;
		numOfNeighbor = 0;
		neighbor = nullptr;
		step = MAXN;
	}
};

Node nodes[MAXN];
int node[MAXN]; //simulate stack
int nodeSt = 0, nodeEnd = 0;
Node *canCalNode = nullptr;

void init() {
		for (int i = 0; i <= numOfNode; i++) {
				nodes[i] = Node(i);
		}
		nodes[1].step = 0; 
}

void addNeighbor(int nStart, int nEnd) {
		if (nodes[nStart].neighbor == nullptr) {
				nodes[nStart].neighbor = new NodeNo(nEnd);
		}
		else {
				NodeNo *no = nodes[nStart].neighbor;
				while (no->next != nullptr) no = no->next;
				no->next = new NodeNo(nEnd);
		}
}

int main() {
	int numOfEdge;
	int nStart, nEnd, weight, nWeight;
	std::cin >> numOfNode >> numOfEdge >> weight;
	
	init();

	while (numOfEdge--) {
		std::cin >> nStart >> nEnd >> nWeight;
		if (nWeight < weight) continue;	
		addNeighbor(nStart, nEnd);
		addNeighbor(nEnd, nStart);
	}

	node[nodeEnd++] = 1;
	while (nodeSt != nodeEnd) {
		int dealNo = node[nodeSt];
		NodeNo *dealNeighbor = nodes[dealNo].neighbor;
		while (dealNeighbor != nullptr) {
			int nextNo = dealNeighbor->no;
			if (nodes[nextNo].step > nodes[dealNo].step + 1) {
				nodes[nextNo].step = nodes[dealNo].step + 1;
				node[nodeEnd++] = nextNo;
			}
			dealNeighbor = dealNeighbor->next;
		}
		nodeSt++;
	}
	if (nodes[numOfNode].step != MAXN)
		std::cout << nodes[numOfNode].step << std::endl;
	else std::cout << "-1" << std::endl;
	return 0;
}

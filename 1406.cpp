 
#include <iostream>
#include <vector>
#include <algorithm>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>

struct Node {
	int a, b;
	int cost;
};

bool cmp(Node a, Node b) {
	return a.cost <= b.cost;
}

int connect[26];

int findParent(int pos) {
	while (connect[pos] != -1) pos = connect[pos];
	return pos;
}

int main() {
	int numOfNode, numOfChild, result, count;
	std::vector<Node> nodes;
	
	while (1) {
		std::cin >> numOfNode;
		if (numOfNode == 0) break;
		
		nodes.clear();
		for (int i = 0; i < numOfNode - 1; i++) {
			std::string beginA, beginB;
			std::cin >> beginA >> numOfChild; 
			for (int j = 0; j < numOfChild; j++) {
				Node node;
				node.a = beginA[0] - 'A';
				std::cin >> beginB >> node.cost;
				node.b = beginB[0] - 'A';
				nodes.push_back(node);
			}
		}
		std::sort(nodes.begin(), nodes.end(), cmp);
		
		result = 0;
		count = 0;
		memset(connect, -1, sizeof(connect));
		for (int i = 0; i < nodes.size(); i++) {
			if (count == numOfNode - 1) break;
			int a = findParent(nodes[i].a), b = findParent(nodes[i].b);
			if (a == b) continue;
			else {
				connect[a] = b;
				result += nodes[i].cost;
				count++;
			}
		}
		std::cout << result << std::endl;
	}
	return 0;
}
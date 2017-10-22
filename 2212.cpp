#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

class Node {
	public:
		int num;
		long long period;
		int operiod;
		Node *pre, *next;

		Node() {}
		Node (int n, int p) {
			num = n;
			period = p;
			operiod = p;
			pre = NULL;
			next = NULL;
		}
};

int cmp(Node *a, Node *b) {
	if (a->period == b->period) return a->num < b->num;
	return a->period < b->period;
}

int main() {
	std::string str;
	int n, numOfTest;
	long long p;
	std::vector<Node *> nodes;
	while (1) {
		std::cin >> str;
		if (str[0] == '#') break;
		std::cin >> n >> p;
		Node *node = new Node(n, p);
		nodes.push_back(node);
	}

	std::cin >> numOfTest;
	while (numOfTest--) {
		std::sort(nodes.begin(), nodes.end(), cmp);
		std::cout << nodes[0]->num << std::endl;
		nodes[0]->period += nodes[0]->operiod;    		
	}

	return 0;
}

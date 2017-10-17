#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

class Node {
	public:
		int price;
		int count;
		std::vector<std::string> names;
		Node() {
			price = 0;
			count = 0;
			names.clear();
		}
		Node(int num, std::string name) {
			price = num;
			count = 1;
			names.push_back(name);
		}
};

int cmp(Node *a, Node *b) {
	if (a->count == b->count) return a->price < b->price;
	return a->count < b->count;
}

int main() {
	int numOfCase, maxPrice, numOfBid;
	std::vector<Node *> nodes;
	std::cin >> numOfCase;
	std::string name;
	int num;
	for (int i = 1; i <= numOfCase; i++) {
		std::cin >> maxPrice >> numOfBid;
		nodes.clear();
		for (int j = 0; j < numOfBid; j++) {
			std::cin >> name >> num;

			int k;
			for (k = 0; k < nodes.size(); k++) {
				if (nodes[k]->price == num) {
					nodes[k]->count++;
					nodes[k]->names.push_back(name);
					break;
				}
			}
			if (k == nodes.size()) {
				Node *node = new Node(num, name);
				nodes.push_back(node);
			}
		}
		std::sort(nodes.begin(), nodes.end(), cmp);

		std::cout << "Case " << i << ":" << std::endl;
		std::cout << "The Winner is " << nodes[0]->names[0] << "." << std::endl;
		std::cout << "The price is " << nodes[0]->price << "." << std::endl;
		if (i < numOfCase) std::cout << std::endl;
	}

	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

#define MAXN 100000

class Node {
	public:
		int a, b;
		Node() {};
		Node(int i, int j) {
			a = i;
			b = j;
		}
};

int cmp(Node *a, Node *b) {
	if (a->a == b->a) return a->b < b->b;
	return a->a < b->a;
}

int main() {
	std::string word;
	std::vector<Node*> pairs;
	std::stack<int> leftword;
	std::cin >> word;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '(') {
			leftword.push(i);
		}
		else {
			Node *node = new Node(leftword.top(), i);
			leftword.pop();
			pairs.push_back(node);

			if (leftword.empty()) {
				//output
				std::sort(pairs.begin(), pairs.end(), cmp);
				for (int i = 0; i < pairs.size(); i++) {
					std::cout << pairs[i]->a + 1 << " " << pairs[i]->b + 1 << std::endl;
				}
				pairs.clear();
			}
		}
	}
}

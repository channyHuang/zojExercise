#include <iostream>

#define MAXN 101

class Node {
	public:
		int index;
		int value;
		int score[MAXN];
		int maxNum;
		Node *pre, *next, *parent;

		Node(){}
		Node(int idx, int v) {
			index = idx;
			value = v;
			maxNum = 0;
			parent = NULL;
			pre = NULL;
			next = NULL;

			maxNum = 1;
			for (int i = 0; i < MAXN; i++) {
				score[i] = 0;
			}
			score[1] = v;
		}

		int getScore(int i) {
			if (i >= maxNum) return 0;
			return score[i];
		}
};

Node *nodes[MAXN];

void compute(Node *root) {
	if (root->pre == NULL && root->next == NULL)	return;

	compute(root->pre);
	compute(root->next);

	root->maxNum = root->pre->maxNum + root->next->maxNum + 1;
	for (int i = 1; i < root->maxNum; i++) {
		for (int j = 0; j <= i; j++) {
			int num = root->value + root->pre->score[j] + root->next->score[i-j];
			if (num > root->score[i+1]) root->score[i+1] = num;
		}
	}
}

int main() {
	int numOfNode, targetNum;
	int a, b, i;
       	std::cin >> numOfNode >> targetNum;
	for (i = 0; i < numOfNode; i++) {
		std::cin >> a;
		nodes[i] = new Node(i, a);
	}
	for (i = 0; i < numOfNode - 1; i++) {
		std::cin >> a >> b;
		nodes[i]->pre = nodes[a-1];
		nodes[i]->next = nodes[b-1];
		nodes[a-1]->parent = nodes[i];
		nodes[b-1]->parent = nodes[i];
	}
	for (i = 0; i < numOfNode; i++) {
		if (nodes[i]->parent == NULL) break;
	}
	for (i = 0; i < numOfNode; i++) {
		std::cout << nodes[i]->index << " " << nodes[i]->value << std::endl;
	}

	Node *root = nodes[i];

	std::cout << "root:" << i << std::endl;
	compute(root);

	std::cout << root->score[targetNum] << std::endl;

	return 0;
}

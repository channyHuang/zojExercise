#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

#define MAXN 128

long long image[MAXN][MAXN];
int scale;
int block[8] = {1, 2, 4, 8, 16, 32, 64, 128};

class Node {
	public:
		int beginPos, endPos; // position
		int value, bw, edge, level; // value is the value of four block, bw (0 both, 1 white, -1 black)
		int count; // num of children (include itself)
		Node *children[4], *parent;

		Node () {
			beginPos = 0;
			endPos = 0;
			value = 0;
			edge = 0;
			level = 0;
			for (int i = 0; i < 4; i++) {
				children[i] = NULL;
				parent = NULL;
			}
		}
		Node(int beginPt, int endPt, int e) {
			beginPos = beginPt;
			endPos = endPt;
			value = 0;
			edge = e;
			level = 0;
			for (int i = 0; i < 4; i++) {
				children[i] = NULL;
				parent = NULL;
			}
		}
};

bool same(Node *a, Node *b) {
	if (a->bw != b->bw) return false;
	if (a->bw == 0) {
		for (int i = 0; i < 4; i++) {
			if (same(a->children[i], b->children[i]) == false) return false;
		}
		return true;
	}
	else return true;
}

Node* build(int beginP, int endP, int e) {
	Node *node = new Node(beginP, endP, e);
	if (e == 2) {
		node->value = image[node->beginPos][node->endPos];
		if (node->value == 0) {
			node->bw = 1;
			node->count = 1;
		}
		else if (node->value == 15) {
			node->bw = -1;
			node->count = 1;
		}
		else {
			node->bw = 0;
			node->count = 5;
		}
	}	
	else {
		int tmpEdge = node->edge/2; 
		node->children[0] = build(node->beginPos, node->endPos, tmpEdge);
		node->children[1] = build(node->beginPos, node->endPos + tmpEdge/2, tmpEdge);
		node->children[2] = build(node->beginPos + tmpEdge/2, node->endPos, tmpEdge);
		node->children[3] = build(node->beginPos + tmpEdge/2, node->endPos + tmpEdge/2, tmpEdge);

		int bw = 0, num = 0;
		for (int i = 0; i < 4; i++) {
			bw += node->children[i]->bw;
			num += node->children[i]->count;
		}
		//combine if same color
		if (bw == -4 || bw == 4) {
			for (int i = 0; i < 4; i++) {
				delete node->children[i];
				node->children[i] = NULL;
			}
			node->count = 1;
		}
		else node->count = num + 1;
	} // end of if(node->edge == 2)
	std::cout << "node:" << node->beginPos << " " << node->endPos << " " << node->edge << " " << node->count << std::endl;
	return node;
}

int main() {
	int numOfRow, numOfCol;
	std::string str;
	long long resultQuad, resultSquad;
	while (1) {
		//input
		std::cin >> numOfRow >> numOfCol;
		if (numOfRow == 0 && numOfCol == 0) break;
		memset(image, 0, sizeof(image));
		int i = 0;
		scale = std::max(numOfRow, numOfCol);
		while(scale > block[i]) i++;
		scale = block[i];
		for (i = 0; i < numOfRow; i++) {
			std::cin >> str;
			for (int j = 0; j < numOfCol; j++) {
				image[i/2][j/2] = (image[i/2][j/2] << 1) + str[j] - '0';
			}
		}
		//compute
		Node *root = build(0, 0, scale);
		//output
		std::cout << root->count << " " << std::endl;
	}
	return 0;
}

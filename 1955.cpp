#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>

#define MAXN 520

class Node {
	public:
		int beginPos, endPos;
		int scale;

		Node(int scales) {
			scale = scales;
			beginPos = 0;
			endPos = 0;
		}
		Node(int scales, int beginPt, int endPt) {
			scale = scales;
			beginPos = beginPt;
			endPos = endPt;
		}
};

char bits[MAXN][MAXN];

int main() {
	int scales;
	std::string codes;
	std::cin >> scales >> codes;
	std::stack<Node *> nodes;
	nodes.push(new Node(scales));
	Node *curNode;
	for (int i = 0; i < codes.length(); i++) {
		curNode = nodes.top();
		nodes.pop();
		switch(codes[i]) {
			case 'Q':
				nodes.push(new Node(curNode->scale/2, curNode->beginPos, curNode->endPos));
				nodes.push(new Node(curNode->scale/2, curNode->beginPos + curNode->scale/2, curNode->endPos));
				nodes.push(new Node(curNode->scale/2, curNode->beginPos, curNode->endPos + curNode->scale/2));
				nodes.push(new Node(curNode->scale/2, curNode->beginPos + curNode->scale/2, curNode->endPos + curNode->scale/2));
				break;
			case 'W':
			case 'B':
				for (int x = curNode->beginPos; x < curNode->beginPos + curNode->scale; x++) {
					for (int y = curNode->endPos; y < curNode->endPos + curNode->scale; y++) {
						bits[x][y] = codes[i];
					}
				}
				break;
			default:
				break;
		}
	}

	std::cout << "#define quadtree_width " << scales << std::endl;
	std::cout << "#define quadtree_height " << scales << std::endl;
	std::cout << "static char quadtree_bits[] = {" << std::endl;
	//output();
	for (int i = 0; i < scales; i++) {// for every line
		int n = 0;
		for (int j = 0; j < scales; j++) {
			n += ((bits[i][j] == 'W') ? 0 : std::pow(2, j%8));
			if (j % 8 == 7) {
				std::cout << "0x";
				printf("%02x", n);
				n = 0;
			        std::cout << ",";
			}
		}
		std::cout << " /*";
		for (int j = 0; j < scales; j++) {
			std::cout << bits[i][j];
			if (j % 8 == 7) std::cout << " ";
		}
		std::cout << "*/" << std::endl;
	}
	
	std::cout << "};" << std::endl;
	return 0;
}

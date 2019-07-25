#include <iostream>

#define MAXN 102

class Node {
public:
	int no;
	bool end;
	Node *children[MAXN];
	Node(int _no = 0) {
		no = _no;
		end = false;
		for (int i = 0; i < MAXN; i++) children[i] = nullptr; 
	}
};

Node *root[MAXN] = {nullptr};

void output(Node *node) {
	if (node == nullptr) return;
	int version[MAXN] = {0};
	int curPos = 0;
	version[curPos + 1] = node->no;
	while(1) {
		
		for (int i = 0; i < MAXN; i++) {
			if (
		}
	}
}

int main() {
	int numOfVersion;
	std::cin >> numOfVersion;
	char cVersion[MAXN];
	for (int i = 0; i < numOfVersion; i++) {
		std::cin >> cVersion;
		int ver = -1;
		Node *curNode = nullptr;
		for (int pos = 0; cVersion[pos] != 0; pos++) {
			if (cVersion[pos] == '.') {
				if (curNode == nullptr) {
					if (root[ver] == nullptr) root[ver] = new Node(ver);
					curNode = root[ver];
				} else {
					if (curNode->children[ver] == nullptr) curNode->children[ver] = new Node(ver);
					curNode = curNode->children[ver];
				}
				ver = -1;	
			} else {
				if (ver == -1) ver = cVersion[pos] - '0';
				else ver = ver * 10 + cVersion[pos] - '0';
			}
		}
		if (ver != -1) {
			if (curNode == nullptr) {
				if (root[ver] == nullptr) root[ver] = new Node(ver);
				curNode = root[ver];
			} else {
				if (curNode->children[ver] == nullptr) curNode->children[ver] = new Node(ver);
				curNode = curNode->children[ver];
			}
			curNode->end = true;
		}
	}

	for (int i = 0; i < MAXN; i++) {
		output(root[i]);
	}

	return 0;
}

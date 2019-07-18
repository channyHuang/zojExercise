#include <iostream>

#define MAXN 1005

class NodeNo {
	int no;
	NodeNo *pre;
	NodeNo *next;
	NodeNo(int _no = 0) {
		no = _no;
		pre = nullptr;
		next = nullptr;
	}
}

class Node {
	int no;
	int dirboss;
	NodeNo *bosses;
	int numOfBoss;
	Node(int _no) {
		no = _no;
		dirboss = -1;
		bosses = nullptr;
		numOfBoss = 0;
	}
}	

Node nodes[MAXN];

bool checkUnDir(int a, int b) {
	NodeNo *bosses = nodes[b].bosses;
	while (bosses != nullptr) {
		if (checkUnDir(a, bosses->no)) return true;
		bosses = bosses->next;
	}
	return false;
}	

int main() {
	int totalNode, totalEdge;
	int A, B;
	std::cin >> totalNode >> totalEdge;
	while (totalEdge--) {
		std::cin >> A >> B;
		if (checkUnDir(A, B)) continue;
		
	}
	
	for (int i = 1; i <= totalNode; i++) {
		std::cout << nodes[i].dirboss;
	}
	return 0;
}

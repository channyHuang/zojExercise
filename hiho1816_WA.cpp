#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAXN 1005

class Node {
public:
	int b;
	int s;
	int dif;
	Node(int _b = 0, int _s = 0) {
		b = _b;
		s = _s;
	}
};

Node nodesB[MAXN], nodesS[MAXN];
int numOfN;

int cmp(const void *a, const void *b) {
	return ((Node *)a)->dif <= ((Node *)b)->dif;
}

int main() {
	std::cin >> numOfN;
	int satisfy = 0;
	int bNum = 0, sNum = 0;
	for (int i = 0; i < numOfN * 2; i++) {
		std::cin >> nodesB[bNum].b >> nodesB[bNum].s; 
		
		if (nodesB[bNum].b >= nodesB[bNum].s) {
			nodesB[bNum].dif = nodesB[bNum].b - nodesB[bNum].s;
			bNum++;
			satisfy += nodesB[bNum - 1].b;
		} else {
			nodesS[sNum].b = nodesB[bNum].b;
			nodesS[sNum].s = nodesB[bNum].s;
			nodesS[sNum].dif = nodesS[sNum].s - nodesS[sNum].b;
			sNum++;
			satisfy += nodesS[sNum - 1].s;
		}	
	}
	//std::cout << bNum << " " << sNum << std::endl;
	if (sNum == bNum) {
		std::cout << satisfy << std::endl;	
	}
	else if (sNum > bNum) {
		std::qsort(nodesS, sNum, sizeof(Node), cmp);
		for (int i = 0; i < sNum - bNum; i++) {
			satisfy -= nodesS[i].dif;
		}
		std::cout << satisfy << std::endl;	

	}
	else {
		std::qsort(nodesB, bNum, sizeof(Node), cmp);
		for (int i = 0; i < bNum - sNum; i++) 
			satisfy -= nodesB[i].dif;
		std::cout << satisfy << std::endl;	
	}
	return 0;
}

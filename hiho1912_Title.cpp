#include <iostream>

#define MAXN 100005

#include <vector>

class Node {
public:
	int no;
	int dirBoss;
	std::vector<int> mate;
	Node(int _no = 0) {
		no = _no;
		dirBoss = -1;
		mate.clear();
	}
};

int numOfNode, numOfEdge;
Node nodes[MAXN];

bool check(int no) {
	for (int i = 0; i < nodes[no].mate.size(); i++) {
		if (nodes[nodes[no].mate[i]].dirBoss == -1) nodes[nodes[no].mate[i]].dirBoss = nodes[no].dirBoss;
		else if (nodes[nodes[no].mate[i]].dirBoss != nodes[no].dirBoss) return false;
	
	}
	return true;
}

int main() {
	std::cin >> numOfNode >> numOfEdge;
	int edgeType, noa, nob;
	int resFlag = 0; //0-normal, 1-uncertain, -1-conflict
	while (numOfEdge--) {
		std::cin >> edgeType >> noa >> nob;
		if (resFlag == -1) continue;
		switch(edgeType) {
		case 1:
			if (nodes[nob].dirBoss != -1) resFlag = -1;
			else {
				nodes[nob].dirBoss = noa;
				if (!check(nob)) resFlag = -1;
			}
			break;
		case 2:
			if (nodes[noa].dirBoss != -1) {
				if (nodes[nob].dirBoss == -1) nodes[nob].dirBoss = nodes[noa].dirBoss;
				else if (nodes[nob].dirBoss != nodes[noa].dirBoss) resFlag = -1;
			} else {
				if (nodes[nob].dirBoss == -1) {
					nodes[noa].mate.push_back(nob);
					nodes[nob].mate.push_back(noa);
				}
				else nodes[noa].dirBoss = nodes[nob].dirBoss;
			}
			break;
		default:
			break;
		}
	}
	if (resFlag == -1) std::cout << "CONFLICT" << std::endl;
	else {
		int count = 0;
		for (int i = 1; i <= numOfNode; i++) {
			if (nodes[i].dirBoss == -1) {
				nodes[i].dirBoss = 0;
				count++;
				if (count >= 2) {
					resFlag = 1;
					break;
				}
			}
		}
		if (resFlag = 1) std::cout << "UNCERTAIN" << std::endl;
		else {
			for (int i = 1; i <= numOfNode; i++) {
				if (i > 1) std::cout << " ";
				std::cout << nodes[i].dirBoss;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}

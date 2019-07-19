#include <iostream>

#define MAXN 100005

class Node {
public:
	int curYear;
	int population;
	Node(int _year = 0, int _pop = 0) {
		curYear = _year;
		population = _pop;
	}
};

int numOfNode, numOfYear, increasePop;
Node nodes[MAXN];

void swap(int a, int b) {
	Node node(nodes[a].curYear, nodes[a].population);
	nodes[a].curYear = nodes[b].curYear;
	nodes[a].population = nodes[b].population;
	nodes[b].curYear = node.curYear;
	nodes[b].population = node.population;
}

void addNode(int pos) {
	int tmp = 0;
	while (pos / 2 != 0) {
		if (nodes[pos].population <= nodes[pos / 2].population) break;
		tmp = nodes[pos / 2].population;
		nodes[pos / 2].population = nodes[pos].population;
		nodes[pos].population = tmp;
		pos = pos / 2;
	}
}

void calcPop(int pos, int year) {
	if (nodes[pos].curYear == year) return;
	nodes[pos].population += (increasePop * (year - nodes[pos].curYear));
	nodes[pos].curYear = year;
}

void adjustNode(int pos, int year) {
	if (pos * 2 > numOfNode) return;
	else {
		calcPop(pos * 2, year);
		int targetPos = pos * 2;
		if (pos * 2 + 1 <= numOfNode) {
			calcPop(pos * 2 + 1, year);
			if (nodes[pos * 2].population < nodes[pos * 2 + 1].population) targetPos = pos * 2 + 1;
		}
		if (nodes[targetPos].population > nodes[pos].population) {
			swap(pos, targetPos);
			adjustNode(targetPos, year);
		}
	}
}

int main() {
	std::cin >> numOfNode >> numOfYear >> increasePop;
	increasePop *= 100;
	for (int i = 1; i <= numOfNode; i++) {
		std::cin >> nodes[i].population;
		addNode(i);
	}
	for (int i = 1; i <= numOfYear; i++) {
		calcPop(1, i);
		nodes[1].population /= 2;
		adjustNode(1, i);
	}
	int res = 0;
	for (int i = 1; i <= numOfNode; i++) {
		calcPop(i, numOfYear);
		res += nodes[i].population;
	}
	std::cout << res << std::endl;
	
	return 0;
}

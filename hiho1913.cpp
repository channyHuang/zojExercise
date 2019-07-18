#include <iostream>

#define MAXN 100005

class Node {
public:
	int curYear;
	int population;
}

int numOfNode, numOfYear, increasePop;
Node nodes[MAXN];

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
	nodes[pos].population += (increasePop * (year - curYear));
}

void adjustNode(int pos, int year) {
	if (pos * 2 > numOfNode) return;
	else if (pos * 2 + 1 > numOfNode) {
		calcPop(pos * 2, year);
		if (nodes[pos * 2].population >

int main() {
	std::cin >> numOfNode >> numOfYear >> increasePop;
	increasePop *= 100;
	for (int i = 1; i <= numOfNode; i++) {
		std::cin >> nodes[i].population;
		addNode(i);
	}
	for (int i = 1; i <= numOfYear; i++) {
		calcPos(1, i);
		nodes[1].population /= 2;
		adjustNode(1, i);
	}
	int res = 0;
	for (int i = 1; i <= numOfNode; i++) {
		calcPos(i, numOfYear);
		res += nodes[i].population;
	}
	std::cout << res << std::endl;
	
	return 0;
}

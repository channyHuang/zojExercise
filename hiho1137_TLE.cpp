#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>

#define MAXN 101

class Node {
	public:
		char gen;
		int ability, salary;

		Node() {}
};

Node *nodes[MAXN];
bool used[MAXN];
int numOfTotal, numOfMale, numOfFemale, budget;
int maxAbility, minSalary;
std::vector<int> indexs;

void getIndex() {
	indexs.clear();
	for (int i = 0; i < numOfTotal; i++) {
		if (used[i]) indexs.push_back(i+1);
	}
}

void dfs(int index, int curMale, int curFemale, int curBudget, int curAbility) {
	if (curMale > numOfMale || curFemale > numOfFemale) return;
	if (curMale == numOfMale && curFemale == numOfFemale) {
		//judge if it is result
		if (curAbility > maxAbility) {
			maxAbility = curAbility;
			minSalary = curBudget;
			getIndex();
		}
		else if (curAbility == maxAbility && curBudget < minSalary) {
			minSalary = curBudget;
			getIndex();
		}
		else return;
	}	
	if (index >= numOfTotal) return;

	for (int i = index; i < numOfTotal; i++) {
		if (used[i]) continue;
		if (curBudget + nodes[i]->salary > budget) continue;
		used[i] = true;
		if (nodes[i]->gen == 'M')	dfs(i+1, curMale+1, curFemale, curBudget + nodes[i]->salary, curAbility + nodes[i]->ability);
		else dfs(i+1, curMale, curFemale + 1, curBudget + nodes[i]->salary, curAbility + nodes[i]->ability); 
		used[i] = false;
	}
}

int main() {
	std::cin >> numOfTotal >> numOfMale >> numOfFemale >> budget;
	maxAbility = 0;
	minSalary = 0;
	for (int i = 0; i < numOfTotal; i++) {
		nodes[i] = new Node();
		std::cin >> nodes[i]->gen >> nodes[i]->ability >> nodes[i]->salary;
		minSalary += nodes[i]->salary;
	}
	
	for (int i = 0; i < numOfTotal; i++) {
		used[i] = false;
	}
	dfs(0, 0, 0, 0, 0);
	std::cout << maxAbility << " " << minSalary << std::endl;
	for (int i = 0; i < indexs.size(); i++) {
		if (i > 0) std::cout << " ";
		std::cout << indexs[i];
	}
	std::cout << std::endl;
	return 0;
}

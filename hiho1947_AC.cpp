#include <iostream>
#include <stack>

#define MAXN 1005

int relation[MAXN][MAXN] = {0};//boss-sub
int dirBoss[MAXN] = {-1};

int main() {
	int totalNode, totalEdge;
	int A, B;
	std::cin >> totalNode >> totalEdge;
	while (totalEdge--) {
		std::cin >> A >> B;
		relation[A][B] = 1;
		relation[A][0]++;
		relation[0][B]++;
	}
	int targetPos = 0;
	for (int i = 1; i <= totalNode; i++) {
		if (relation[0][i] == 0) {
			 targetPos = i;
			 break;
		}
	}

	dirBoss[targetPos] = 0;
	std::stack<int> sureBoss;
	sureBoss.push(targetPos);
	while (!sureBoss.empty()) {	
		targetPos = sureBoss.top();
		sureBoss.pop();
		for (int i = 1; i <= totalNode; i++) {
			if (relation[targetPos][i] != 1) continue;
			if (relation[0][i] == 1) {
				dirBoss[i] = targetPos;
				sureBoss.push(i);
			} else {
				relation[0][i]--;
			}
		}
	}

	for (int i = 1; i <= totalNode; i++) {
		std::cout << dirBoss[i] << std::endl;
	}

	return 0;
}

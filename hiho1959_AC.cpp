#include <iostream>

#define MAXN 105
int fishLeft[MAXN];
int fishRight[MAXN];

int main() {
	int numOfFish;
	std::cin >> numOfFish;
	for (int i = 0; i < numOfFish; i++) {
		std::cin >> fishLeft[i];
	}
	for (int i = 0; i < numOfFish; i++) {
		std::cin >> fishRight[i];
	}
	int posLeft = 0, posRight = 0;
	while (posLeft != numOfFish && posRight != numOfFish) {
		if (fishLeft[posLeft] > fishRight[posRight]) posRight++;
		else posLeft++;
	}
	std::cout << numOfFish - posLeft + numOfFish - posRight << std::endl;
	return 0;
}

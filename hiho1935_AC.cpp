#include <iostream>

#define MAXN 100005

struct Flower {
	long long distance;
	long long water;
	Flower() {
		distance = 0;
		water = 0;
	}
};

int numOfFlower, glassVal;
Flower flower[MAXN];

int main() {
	std::cin >> numOfFlower >> glassVal;
	long long curVal = glassVal;
	long long totalDis = 0;
	for (int i = 1; i <= numOfFlower; i++)
		std::cin >> flower[i].distance;
	for (int i = 1; i <= numOfFlower; i++) { 
		std::cin >> flower[i].water;	
		if (curVal >= flower[i].water) {
			curVal -= flower[i].water;	
			totalDis += flower[i].distance - flower[i - 1].distance;
		} else {
			curVal = glassVal - flower[i].water;
			totalDis += flower[i - 1].distance + flower[i].distance;
		}
		//std::cout << i << " " << curVal << " " << totalDis << std::endl;
	}
	std::cout << totalDis + flower[numOfFlower].distance << std::endl;
	return 0;
}

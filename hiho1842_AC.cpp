#include <iostream>

#define MAXN 1005

 

int main() {
	int numOfA, numOfB;
	std::cin >> numOfA >> numOfB;
	int oneOfA = numOfA, twoOfA = 0;
	int oneOfB = numOfB, twoOfB = 0;
	int blockOfA, blockOfB;
	bool flag = false;
	for (; oneOfA >= 0; oneOfA -= 2, twoOfA++) {
		blockOfA = oneOfA + twoOfA;

		if (blockOfA > numOfB + 1 || blockOfA < numOfB / 2 + numOfB % 2 - 1) continue;

		for (oneOfB = numOfB, twoOfB = 0; oneOfB >= 2; oneOfB -= 2, twoOfB++) {
			if (oneOfB + twoOfB <= blockOfA + 1 && oneOfB + twoOfB >= blockOfA - 1) break;
		}
		blockOfB = oneOfB + twoOfB;
		if (blockOfB <= blockOfA + 1 && blockOfB >= blockOfA - 1) {
			flag = true;
			break;
		}
	}
	//std::cout << oneOfA << " " << twoOfA << " " << blockOfB << " " <<  flag << std::endl;
	bool lastChar = 1;//0-A, 1-B
	if (flag) {
		while(blockOfA || blockOfB) {
				
			if (blockOfA > blockOfB) {
				if (oneOfA) {
					std::cout << "A";
					oneOfA--;
				} else {
					std::cout << "AA";
					twoOfA--;
				}
				blockOfA--;
				lastChar = 0;
			} else if (blockOfB > blockOfA) {
				if (oneOfB) {
					std::cout << "B";
					oneOfB--;
				} else {
					std::cout << "BB";
					twoOfB--;
				}
				blockOfB--;
				lastChar = 1;
			} else {
				if (lastChar == 1) {
					if (oneOfA) {
						std::cout << "A";
						oneOfA--;
					} else {
						std::cout << "AA";
						twoOfA--;
					}
					if (oneOfB) {
						std::cout << "B";
						oneOfB--;
					} else {
						std::cout << "BB";
						twoOfB--;
					}
				} else {
					if (oneOfB) {
						std::cout << "B";
						oneOfB--;
					} else {
						std::cout << "BB";
						twoOfB--;
					}
					if (oneOfA) {
						std::cout << "A";
						oneOfA--;
					} else {
						std::cout << "AA";
						twoOfA--;
					}
				}
				blockOfA--;
				blockOfB--;
			}
		}

	}
	else std::cout << "-1" << std::endl;
	return 0;
}

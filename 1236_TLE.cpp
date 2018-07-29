#include <iostream>
#include <vector>
#include <algorithm>

int date;

class Cow {
public:
	int index, T;
	int milk[11];;
	
	Cow() {}
	Cow(int i) {
		index = i;
	}
};

int lcm(int a, int b) {
	int x = a, y = b;
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	while (x) {
		y %= x;
		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
	}
	return a / y * b;
}

std::vector<Cow> cows;

void output(std::vector<Cow> cows) {
	std::cout << "output:" << std::endl;
	for (int i = 0; i < cows.size(); i++) {
		std::cout << cows[i].index << " " << cows[i].T << std::endl;
	}
}

int main() {
	int testCase, lcmNum = 1, lastDate = 0;
	int numOfCow;
	std::cin >> testCase;
	while(testCase--) {
		date = 0;
		int leastIdx = 0, secondIdx = 1;
		cows.clear();
		std::cin >> numOfCow;
		for (int i = 0; i < numOfCow; i++) {
			Cow cow = Cow(i);
			std::cin >> cow.T;
			lcmNum = lcm(cow.T, lcmNum);
			for (int j = 0; j < cow.T; j++) {
				std::cin >> cow.milk[j];
			}
			if (i > 0 && cow.milk[0] <= cows[leastIdx].milk[0]) {
				secondIdx = leastIdx;
				leastIdx = i;
			}
			cows.push_back(cow);
		}
		while (date <= 2 * lcmNum) {
			//output(cows);
			if (cows.size() == 1) {	
				lastDate = date + 1;
				cows.clear();
				break;
			}
			if (cows[leastIdx].milk[date % cows[leastIdx].T] != cows[secondIdx].milk[date % cows[secondIdx].T]) {
				lastDate = date + 1;
				cows.erase(cows.begin() + leastIdx);
			}
			date++;
			leastIdx = 0;
			secondIdx = 1;	
			for (int i = 1; i < cows.size(); i++) {
				if (cows[i].milk[date % cows[i].T] <= cows[leastIdx].milk[date % cows[leastIdx].T]) {
					secondIdx = leastIdx;
					leastIdx = i;
				}
			}
		}
		std::cout << cows.size() << " " << lastDate << std::endl;
	}
	return 0;
}

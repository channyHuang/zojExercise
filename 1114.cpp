#include <iostream>

#define MAXN 100005

int result[MAXN];//-2 not set, -1 not boom, 0 not sure, 1 boom
int numOfBoom = 0, numOfNotBoom = 0;
int numbers[MAXN] = {0};

//booms[pos-1] + booms[pos] + booms[pos+1]
int sumOfPos(int pos, bool booms[], int width) {
	int res = (booms[pos] ? 1 : 0);
	if (pos > 0) res += (booms[pos - 1] ? 1 : 0);
	if (pos < width - 1) res += (booms[pos + 1] ? 1 : 0);
	return res;
}	

void dfs(int curPos, bool booms[], int width) {
	if (curPos >= width) {
		if (sumOfPos(width - 1, booms, width) != numbers[width - 1]) return;
		for (int i = 0; i < width; i++) {
			if (result[i] == -2) {
				result[i] = (booms[i] ? 1 : -1);
				if (booms[i]) numOfBoom++;
				else numOfNotBoom++;
			}
			else if (result[i] == -1 && booms[i]) {
				result[i] = 0;
				numOfNotBoom--;
			}
			else if (result[i] == 1 && !booms[i]) {
				result[i] = 0;
				numOfBoom--;
			}
		}
		return;
	}

	booms[curPos] = true;
	if (curPos == 0 || sumOfPos(curPos - 1, booms, width) == numbers[curPos - 1]) 
		dfs(curPos + 1, booms, width);

	booms[curPos] = false;
	if (curPos == 0 || sumOfPos(curPos - 1, booms, width) == numbers[curPos - 1])
		dfs(curPos + 1, booms, width);
}

int main()
{
	int numOfCase;
	std::cin >> numOfCase;
	while(numOfCase--) {
		numOfBoom = 0;
		numOfNotBoom = 0;
		for (int i = 0; i < MAXN; i++) result[i] = -2;

		int width = 0;
		bool booms[MAXN] = {0};
		std::cin >> width;
		for (int i = 0; i < width; i++) {
			std::cin >> numbers[i];
		}
		dfs(0, booms, width);

		std::cout << numOfBoom;
		for (int i = 0; i < width; i++) {
			if (result[i] == 1) std::cout << " " << i + 1;
		}
		std::cout << std::endl << numOfNotBoom;
		for (int i = 0; i < width; i++) {
			if (result[i] == -1) std::cout << " " << i + 1;
		}
		std::cout << std::endl;
	}
	return 0;
}

#include <iostream>
#include <vector>

bool debug = true;
std::vector<long> numbers, leaks;

void swap(long &a, long &b) {
	long tmp = a;
	a = b;
	b = tmp;
}

void add(int curPos, int heapLen) {
	int index, maxIdx;
	if (curPos >= heapLen) {
		if (numbers[curPos] < numbers[0]) {
			swap(numbers[curPos], numbers[0]);
			//modify big heap
			index = 0;
			while (1) {
				if (index*2+1 >= heapLen) break;
				else if (index*2+2 >= heapLen) {
					if (numbers[index] < numbers[index*2+1]) swap(numbers[index], numbers[index*2+1]);
					break;
				}
				else {
					maxIdx = (numbers[index*2+1] > numbers[index*2+2] ? index*2+1 : index*2+2);
					if (numbers[index] < numbers[maxIdx]) {
						swap(numbers[index], numbers[maxIdx]);
						index = maxIdx;
					}
					else break;					
				}			
			}
		}		
		//add numbers[curPos] to small heap
		leaks.push_back(numbers[curPos]);
		curPos = leaks.size();
		while (curPos > 0 && leaks[curPos] < leaks[(curPos-1)/2]) {
			swap(leaks[curPos], leaks[(curPos-1)/2]);
			curPos = (curPos - 1) / 2;
		}
	}
	else {
		//modify big heap
		while (curPos > 0 && numbers[curPos] > numbers[(curPos-1)/2]) {
			swap(numbers[curPos], numbers[(curPos-1)/2]);
			curPos = (curPos - 1) / 2;
		}
	}
}

void outputBigHeap() {
	int len = numbers.size();
	for (int i = 0; i < len; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int totalNum, totalTest, numOfCase, pos, curPos = 1;
	int heapLen, heapTail;
	std::cin >> numOfCase;
	long num;
	while (numOfCase--) {
		std::cin >> totalNum >> totalTest;
		heapTail = 1;
		numbers.clear();
		leaks.clear();
		curPos = 1;
		for (int i = 0; i < totalNum; i++) {
			std::cin >> num;
			numbers.push_back(num);
		}
		if (debug) std::cout << totalNum << "," << totalTest << std::endl;
		if (debug) outputBigHeap();
		for (int heapLen = 1; heapLen <= totalTest; heapLen++) {
			std::cin >> pos;
			while (curPos != pos) {
				add(curPos, heapLen);
				curPos++;
				if (debug) {
					std::cout << "curPos=" << curPos << std::endl;
					outputBigHeap();
				}
			}
			
			if (debug) std::cout << heapLen << ":" << curPos <<","<<pos<< std::endl;
			std::cout << numbers[0] << std::endl;
		}
	}
	return 0;
}
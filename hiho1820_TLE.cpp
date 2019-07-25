#include <iostream>

#define MAXN 100005

class Node {
public:
	int num;
	int count;
	int pre;
	int next;
	Node(int _num = 0) {
		num = _num;
		count = 1;
		pre = 0;
		next = 0;
	}
};

Node nodes[MAXN];
int numOfN;
int headNo = 1, tailNo = 1;

void adjust(int no) {
	if (no == 1) return;
	int curNo = headNo;
	while (curNo != 0) {
		if (nodes[curNo].num == nodes[no].num) {
			nodes[curNo].count++;
			return;
		}

		if (nodes[curNo].num < nodes[no].num) {
			if (nodes[curNo].next != 0) curNo = nodes[curNo].next;
			else {
				nodes[no].pre = curNo;
				nodes[curNo].next = no;
				tailNo = no;
				return;
			}
		} else {
			nodes[no].next = curNo;
			nodes[no].pre = nodes[curNo].pre;
			nodes[nodes[curNo].pre].next = no;
			nodes[curNo].pre = no;
			if (headNo == curNo) headNo = no;
			return;
		}
	}
}

void output() {
	int i = headNo;
	while (i != 0) {
		std::cout << nodes[i].num << " " << nodes[i].count << std::endl;
		i = nodes[i].next;
	}
}

int main() {
	long long totalLen = 0;
	int tmp;
	std::cin >> numOfN;
	for (int i = 1; i <= numOfN; i++) {
		std::cin >> nodes[i].num;
		totalLen += nodes[i].num;
		adjust(i);
	}
	//output();	
	int curNo = headNo;
	int curCut = 0;
	while(curNo != 0) {	
		totalLen -= (numOfN * (nodes[curNo].num - curCut));	
		numOfN -= nodes[curNo].count;
		curCut = nodes[curNo].num;
		curNo = nodes[curNo].next;
		std::cout << totalLen << std::endl;
		
	}
	return 0;
}

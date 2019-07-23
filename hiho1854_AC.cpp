#include <iostream>

#define MAXN 10005

class Node {
public:
	int seconds;
	Node *next;
	Node *pre;
	Node(int _sec = 0) {
		pre = nullptr;
		next = nullptr;
		seconds = _sec;
	}
};

Node *nodes[MAXN];

int changeTimeToSec(char time[10]) {
	int hour = (time[0] - '0') * 10 + time[1] - '0';
	int minute = (time[3] - '0') * 10 + time[4] - '0';
	int sec = (time[6] - '0') * 10 + time[7] - '0';
	return hour * 3600 + minute * 60 + sec;
}

int main() {
	int numOfTime;
	int tmpNo;
	char tmpTime[10];
	std::cin >> numOfTime;
	while (numOfTime--) {
		std::cin >> tmpNo >> tmpTime;

		int sec = changeTimeToSec(tmpTime);
		if (nodes[tmpNo] == nullptr) {
			nodes[tmpNo] = new Node(sec);
			continue;
		}
		Node *newNode = new Node(sec);
		Node *curNode = nodes[tmpNo];
		if (curNode->seconds > sec) {
			curNode->pre = newNode;
			newNode->next = curNode;
			nodes[tmpNo] = newNode;
			continue;
		}
		while(curNode->next != nullptr && curNode->next->seconds < sec) curNode = curNode->next;
		if (curNode->next == nullptr) {
			curNode->next = newNode;
			newNode->pre = curNode;
		} else {
			newNode->next = curNode->next;
			newNode->pre = curNode;
			curNode->next->pre = newNode;
			curNode->next = newNode;
		}
	}
	//std::cout << "input finish" << std::endl;
	for (int i = 1; i < MAXN; i++) {
		if (nodes[i] == nullptr) continue;
		int count = 1;
		bool flag = false;
		Node *preNode = nodes[i], *backNode = nodes[i];
		while (preNode->next != nullptr && count < 5) {
			preNode = preNode->next;
			count++;
		}
		if (count < 5) continue;
		while (preNode != nullptr) {
			if (preNode->seconds - backNode->seconds <= 60 * 60) {
				flag = true;
				break;
			}
			preNode = preNode->next;
			backNode = backNode->next;
		}
		if (flag) std::cout << i << std::endl;
	}
	return 0;
}

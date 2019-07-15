#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAXN 100005
char astr[MAXN], bstr[MAXN];
/*
abb  
bbaa
3
*/

struct NodeNo {
	int pos;
	NodeNo *next;
	NodeNo(int _pos = 0) {
		pos = _pos;
		next = nullptr;
	}
};

struct Node {
	int no;
	NodeNo *pos;
	Node(int _no = 0) {
		no = _no;
		pos = nullptr;
	}
};

Node nodes[30];

int main() {
	for (int i = 0; i < 30; i++) nodes[i] = Node(i);
	std::cin >> astr >> bstr;
	int len = 0;
	while (astr[len] != 0) {
		NodeNo *addPos = nodes[astr[len] - 'a'].pos;
		if (addPos == nullptr) nodes[astr[len] -'a'].pos = new NodeNo(len);
		else {
			while (addPos->next != nullptr) addPos = addPos->next;
			addPos->next = new NodeNo(len);
		}
		len++;
	}
	
	int step = 1;
	int curPos = -1;
	len = 0;
	while (bstr[len] != 0) {
		NodeNo *pos = nodes[bstr[len] - 'a'].pos;
		if (pos == nullptr) {
			step = -1;
			break;
		}
		while(pos->pos <= curPos && pos->next != nullptr) pos = pos->next;
		if (pos->pos <= curPos) {
			step++;
			curPos = nodes[bstr[len] - 'a'].pos->pos;
		}
		else curPos = pos->pos;
		len++;	
	}

	std::cout << step << std::endl;	

	return 0;
}

#include <iostream>

int totalRow, totalCol;
int a, b, c, d;

#define MAXN 100007
class Node {
public:
	long long pos;
	int x, y;
	Node *next;
	Node *pre;
	Node(long long _pos = 0, long long _x = 0, long long _y = 0) {
		pos = _pos;
		x = _x;
		y = _y;
		next = nullptr;
		pre = nullptr;
	}
};

Node *nodes[MAXN] = {nullptr};
long long mapPos(long long x, long long y) {
	return (x % MAXN * totalRow % MAXN + y % MAXN) % MAXN;
}

void search(long long x, long long y, int &res) {
	if (x <= 0 || x > totalRow || y <= 0 || y > totalCol) return;
	long long pos = mapPos(x, y);
	//std::cout << "s" << x << " " << y << " " << pos << std::endl;
	Node *curNode = nodes[pos];
	if (curNode == nullptr) {
		nodes[pos] = new Node(pos, x, y);
		res++;
		//std::cout << x << " " << y << std::endl;
		search(x + a, y + b, res);
		search(x + c, y + d, res);
		return;
	}
		
	while (curNode != nullptr) {
		if (curNode->x == x && curNode->y == y) return;
		if (curNode->next == nullptr) break;
		else curNode = curNode->next;
	}
	
	curNode->next = new Node(pos, x, y);
	res++;

	search(x + a, y + b, res);
	search(x + c, y + d, res);
	
}

int main() {
	std::cin >> totalRow >> totalCol;
	long long startX, startY;
	std::cin >> startX >> startY;
	int res = 0;
	std::cin >> a >> b >> c >> d;
	search(startX, startY, res);
	std::cout << res - 1 << std::endl;
	return 0;
}

#include <iostream>

int titleHeight, totalHeight, totalWidth;

class Node {
public:	
	int index, x1, y1, x2, y2; //x1 < x2, y2 < y1, H < (y1-y2)
	bool maximized;
	int ox1, oy1, ox2, oy2;
	Node *pre, *next;

	Node() {}
	Node(int idx) {
		index = idx;
		maximized = false;
		pre = NULL;
		next = NULL;
	}

	int beClick(int x, int y) {//return 2:title 1: window 0: no
		if (x1 <= x && x2 >= x && y2 <= y) {
		       if (y1 - titleHeight > y) {
				return 1;
		       }
		       else if (y1 >= y) return 2;
		}
		return 0;
	}

	void doubleClick() {
		if (maximized) {
			x1 = ox1;
			y1 = oy1;
			x2 = ox2;
			y2 = oy2;
		}
		else {
			x1 = 0;
			y1 = totalHeight;
			x2 = totalWidth;
			y2 = 0;
		}
		maximized = !maximized;
	}	
};

Node *head;

void moveToFront(Node *node) {
	if (node->index == head->index) return;
	node->pre->next = node->next;
	if (node->next != NULL) {
		node->next->pre = node->pre;
	}
	node->next = head;
	node->pre = NULL;
	head->pre = node;
	head = node;
}

int main() {
	int numOfWin, numOfClick;
	int x, y, prex, prey, clickIdx;
	while (std::cin >> numOfWin) {
		head = NULL;
		std::cin >> titleHeight >> totalWidth >> totalHeight;
		for (int i = 0; i < numOfWin; i++) {
			Node *node = new Node(i);
			std::cin >> node->x1 >> node->y1 >> node->x2 >> node->y2;
			node->ox1 = node->x1;
			node->ox2 = node->x2;
			node->oy1 = node->y1;
			node->oy2 = node->y2;
			//from back to front order
			if (head == NULL) {
				head = node;
			}
			else {
				head->pre = node;
				node->next = head;
				head = node;
			}
		}
		prex = -1;
		prey = -1;
		std::cin >> numOfClick;
		while (numOfClick--) {
			std::cin >> x >> y;
			clickIdx = -1;
			Node *curNode = head;
			while (curNode != NULL) {
				int clickResult = curNode->beClick(x, y);
				if (clickResult != 0) {
					if (clickResult == 2) {
					       	if( x == prex && y == prey) {
							curNode->doubleClick();
							prex = -1;
							prey = -1;
						}
					}
					clickIdx = curNode->index;
					moveToFront(curNode);
					break;
				}
				curNode = curNode->next;
			}
			prex = x;
			prey = y;
			std::cout << clickIdx;
			if (numOfClick) std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

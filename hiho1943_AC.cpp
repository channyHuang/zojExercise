#include <iostream>

#define MAXN 1000005
//2*1
class Rect {
public:
	int x, y;
	Rect *left, *right;
	Rect(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
		left = nullptr;
		right = nullptr;
	}
};
//x, row
Rect *rects[MAXN] = {nullptr};

bool addRect(Rect *root, Rect *rect) {
	if (root->x > rect->x + 1) {
		rect->right = root;
		root->left = rect;
		rects[rect->y] = rect;
		return true;
	}
	if (root->x >= rect->x - 1) return false;
	Rect *preRect = root;
	while (preRect->right != nullptr && preRect->right->x < rect->x - 1) preRect = preRect->right;
	if (preRect->right == nullptr) {
		preRect->right = rect;
		rect->left = preRect;
		return true;
	}
	if (preRect->right->x > rect->x + 1) {
		rect->left = preRect;
		rect->right = preRect->right;
		preRect->right->left = rect;
		preRect->right = rect;
		return true;
	}
	return false;
}

int main() {
	int numOfRect, res = 0;
	int x, y;
	std::cin >> numOfRect;
	for (int i = 0; i < numOfRect; i++) {
		std::cin >> x >> y;
		Rect *rect = new Rect(x, y);
		if (rects[rect->y] == nullptr)  {
			rects[rect->y] = rect;
			res++;
		}
		else if (addRect(rects[rect->y], rect)) res++;
	}
	std::cout << res << std::endl;
	return 0;
}

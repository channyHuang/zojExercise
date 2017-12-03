#include <iostream>

#define MAXN 100001

bool debug = false;

class Node {
	public:
		int level;
		int width, height; //origin size
		int leftWidth; //the width left for this image
		int heightBefore; //the height of this level before this image
		int heightLevelsBefore; //the total height before this level
		Node() {
			level = 0;
			leftWidth = 0;
			heightBefore = 0;
			heightLevelsBefore = 0;
		}
};

Node nodes[MAXN];

int compress(int i, int leftWidth) {
	double height = leftWidth * nodes[i].height * 1.0 / nodes[i].width;
	int result = (int)height;
	if (height - result != 0) result++;
	return result;	
}

int totalWidth, numOfImg;

int sort(int beginIdx, bool includeBegin) {
	
	int curLevel = nodes[beginIdx].level;
	int leftWidth = nodes[beginIdx].leftWidth;
	int heightBefore = nodes[beginIdx].heightBefore;
	int heightLevelsBefore = nodes[beginIdx].heightLevelsBefore;
	if (!includeBegin) beginIdx++;
	for (int i = beginIdx; i < numOfImg; i++) {
		//next level
		if (leftWidth <= 0) {
			curLevel++;
			leftWidth = totalWidth;
			heightLevelsBefore += heightBefore;
			heightBefore = 0;
		}
		nodes[i].level = curLevel;
		nodes[i].leftWidth = leftWidth;
		nodes[i].heightBefore = heightBefore;
		nodes[i].heightLevelsBefore = heightLevelsBefore;
	
		int curHeight = nodes[i].height;
		if (leftWidth < nodes[i].width) {
			curHeight = compress(i, leftWidth);
		}
 		if (curHeight > heightBefore) heightBefore = curHeight;

		leftWidth -= nodes[i].width;	
	}
	if (debug) std::cout << "sort: " << beginIdx << " " << includeBegin << " " << heightLevelsBefore + heightBefore << std::endl;
	return heightLevelsBefore + heightBefore;
}

int main() {
	std::cin >> totalWidth >> numOfImg;
	for (int i = 0; i < numOfImg; i++) {
		std::cin >> nodes[i].width >> nodes[i].height;
	}
	int minHeight = sort(0, true);
	int tmpHeight = 0;
	//begin to delete one, the delete index is i
	for (int i = numOfImg - 1; i >= 0; i--) {
		//for every image after i, rearrange
		tmpHeight = sort(i, false);
		if (tmpHeight < minHeight) minHeight = tmpHeight;
	}	

	std::cout << minHeight << std::endl;
	return 0;
}

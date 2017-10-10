#include <iostream>
#include <vector>

class Node {
	public:
		int beginPos, endPos;
		int color;
		Node *next, *pre;
	
		Node() {
			next = NULL;
			pre = NULL;
		}
		Node(int beginPt, int endPt, int colorPt) {
			beginPos = beginPt;
			endPos = endPt;
			color = colorPt;
			next = NULL;
			pre = NULL;
		}
};
Node *head = NULL;
//curNode: to add; node: already exist
void add(Node *node, Node *curNode, bool addToPre) {
	if (addToPre) {
		curNode->next = node;
		if (node->pre == NULL) {
			head = curNode;
		}
		else {
			node->pre->next = curNode;
			curNode->pre = node->pre;
		}
		node->pre = curNode;
	}
	else {
		curNode->pre = node;
		if (node->next != NULL) {
			node->next->pre = curNode;
			curNode->next = node->next;
		}
		node->next = curNode;
	}
}

void deleteNode(Node *node) {
	if (node->pre == NULL) {
		if (node->next == NULL) {
			head = NULL;
			return;
		}
		node->next->pre = NULL;
		head = node->next;
	}
	else if (node->next == NULL) {
		node->pre->next = NULL;
	}
	else {
		node->next->pre = node->pre;
		node->pre->next = node->next;	
	}
	delete node;
}

void update(Node *node) {
	//update next, node(x1, y1), node->next(x2, y2); x1 <= x2
	while (node->next != NULL) {
		if (node->endPos < node->next->beginPos) break; //x1 y1 x2 y2
		else if (node->endPos == node->next->beginPos) { //x1 y1x2 y2
			if (node->color == node->next->color) {
				node->endPos = node->next->endPos;
				deleteNode(node->next);
			}
		       	break;
		}
		else if (node->endPos >= node->next->endPos) {	//x1 x2 y2 y1
			deleteNode(node->next);
		}
		else {
			if (node->color == node->next->color) {
				node->endPos = node->next->endPos;
				deleteNode(node->next);
			}
			else {
				node->next->beginPos = node->endPos;
			}
			break;
		}
	}
}

void output() {
	Node *node = head;
	std::cout << "output()" << std::endl;
	while (node != NULL) {
		std::cout << node->beginPos << " " << node->endPos << " " << node->color << std::endl;
		node = node->next;
	}
}

int main() {
	int numOfOpt;
	int x1, x2, c;
	bool debug = true;
	Node *node = NULL;
	std::vector<int> colorIdx;
	std::vector<int> colorCount;
	while(std::cin >> numOfOpt) {
		head = NULL;
		for (int i = 0; i < numOfOpt; i++) {
			Node *curNode = new Node();
			std::cin >> curNode->beginPos >> curNode->endPos >> curNode -> color;
			if (head == NULL) {
				head = curNode;
				continue;
			}
			node = head;
			if (debug) std::cout << "numOfOpt:" << i << " " << curNode->beginPos << " " << curNode->endPos << " " << curNode->color << std::endl;
			while (node != NULL) {//to insert curNode, curNode(x1,y1), node(x2,y2)
				if (node->beginPos > curNode->endPos) { // x1 y1 x2 y2 
					//add to pre
					add(node, curNode, true);
					break;
				}
				else if (node->endPos < curNode->beginPos) { // x2 y2 x1 y1
					node = node->next;
					continue;
				}
				else {
					//output();
					if (node->color == curNode->color) {
						node->beginPos = std::min(node->beginPos, curNode->beginPos);
						node->endPos = std::max(node->endPos, curNode->endPos);
						//update next
						update(node);
					}
					else if (node->beginPos >= curNode-> beginPos && node->endPos <= curNode->endPos ){ // x1 x2 y2 y1
						node->beginPos = curNode->beginPos;
						node->endPos = curNode->endPos;
						node->color = curNode->color;
						//update next
						update(node);
					}
					else if (node->beginPos < curNode->beginPos && node->endPos > curNode->endPos) { // x2 x1 y1 y2
						//cut to three segmentation
						Node *newNode = new Node(curNode->endPos, node->endPos, node->color);
						add(node, newNode, false);
						add(node, curNode, false);
						node->endPos = curNode->beginPos;
						//no need to update
					}
					else if (node->beginPos >= curNode->endPos) { // y1 x2
 						node->beginPos = std::max(node->beginPos, curNode->endPos);
						//add to pre
						add(node, curNode, true);
					}
					else if (node->endPos <= curNode->beginPos) {
						add(node, curNode, false);
						update(curNode);
					}
					else //x1 y2
					{//node->endPos > curNode->beginPos && node->beginPos < curNode->endPos
						node->endPos = std::min(node->endPos, curNode->beginPos);
						//add to next and update
						add(node, curNode, false);
						update(curNode);
					}
					output();
					break;
				}
			}//end of while(node != NULL)
		}//end of numOfOpt
		colorIdx.clear();
		colorCount.clear();
		node = head;
		while (node != NULL) {
			int i = 0;
			for (i = 0; i < colorIdx.size(); i++) {
				if (colorIdx[i] == node->color) break;
			}
			if (i < colorIdx.size()) colorCount[i]++;
			else {
				colorIdx.push_back(node->color);
				colorCount.push_back(1);
			}
			node = node->next;
		}
		for (int i = 0; i < colorIdx.size(); i++) {
			std::cout << colorIdx[i] << " " << colorCount[i] << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}

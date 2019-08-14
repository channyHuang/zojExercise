#include <iostream>

#define MAXN 26

class Node {
public:
    char ch;
    Node *children[26];
    bool end;
    Node(char _ch = ' ') {
        ch = _ch;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        end = false;
    }
};
char newOrder[30];
int maps[30] = {0};
Node *root = new Node();

int getMaps(char ch) {
    return maps[ch - 'a'];
}

void output(Node *curNode, int idx, char res[105]) {
    for (int i = 0; i < 26; i++) {
        if (curNode->children[i] == nullptr) continue;

        res[idx] = curNode->children[i]->ch;
        if (curNode->children[i]->end) {
            for (int j = 0; j <= idx; j++) {
                std::cout << res[j];
            }
            std::cout << std::endl;
        }
        output(curNode->children[i], idx+1, res);
    }
}

int main() {
    int numOfStr;
    char str[105];
    std::cin >> numOfStr >> newOrder;
    for (int i = 0; i < 26; i++) {
        maps[newOrder[i] - 'a'] = i;
    }
    for (int i = 0; i < numOfStr; i++) {
        std::cin >> str;
        int j = 0;
        Node *curNode = root;
        while (str[j] != 0) {
            int idx = getMaps(str[j]);
            //std::cout << "idx = " << idx << std::endl;
            if (curNode->children[idx] == nullptr) curNode->children[idx] = new Node(str[j]);
            curNode = curNode->children[idx];
            j++;
        }
        curNode->end = true;
    }

    char res[105] = {0};
    //std::cout << "begin output";
    output(root, 0, res);
    return 0;
}

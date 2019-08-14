
#include <iostream>

#define MAXN 105
#define DEBUG 0

int findEndPos(char str[MAXN], int st) {
    int leftMid = 0, leftLarge = 0;
    if (str[st] == '[') leftMid++;
    else leftLarge++;
    int end = st + 1;
    while (1) {
        switch (str[end]) {
        case '[':
            leftMid++;
            break;
        case ']':
            leftMid--;
            break;
        case '{':
            leftLarge++;
            break;
        case '}':
            leftLarge--;
            break;
        default:
            break;
        }
        if (leftMid == 0 && leftLarge == 0) break;
        end++;
    }
    return end;
}

class Node {
public:
    int st;
    int end;
    bool hasSame;
    Node(int _st = 0, int _end = 0) {
        st = _st;
        end = _end;
        hasSame = false;
    }
};

int checkSub(char str[MAXN], int strSt, int strEnd, Node nodesStr[MAXN]) {
    int numOfSub = 0;
    int nextStrSt = strSt + 1;
    while (nextStrSt != strEnd) {
        int nextStrEnd = findEndPos(str, nextStrSt);
        nodesStr[numOfSub++] = Node(nextStrSt, nextStrEnd);
        nextStrSt = nextStrEnd + 1;
    }
    return numOfSub;
}

bool same(char str[MAXN], char dst[MAXN], int strSt, int strEnd, int dstSt, int dstEnd) {
    if (str[strSt] != dst[dstSt]) return false;
    if (str[strSt] == '[') {
        int nextStrSt = strSt + 1;
        int nextDstSt = dstSt + 1;
        while (nextStrSt != strEnd && nextDstSt != dstEnd) {
            int nextStrEnd = findEndPos(str, nextStrSt);
            int nextDstEnd = findEndPos(dst, nextDstSt);
            if (!same(str, dst, nextStrSt, nextStrEnd, nextDstSt, nextDstEnd)) return false;
            nextStrSt = nextStrEnd + 1;
            nextDstSt = nextDstEnd + 1;
        }
        if (nextStrSt != strEnd || nextDstSt != dstEnd) return false;
    } else {
        Node nodesStr[MAXN], nodesDst[MAXN];
        int numOfSubStr = checkSub(str, strSt, strEnd, nodesStr);
        int numOfSubDst = checkSub(dst, dstSt, dstEnd, nodesDst);

        if (DEBUG) {
            std::cout << "numOfSub " << numOfSubStr << " " << numOfSubDst << std::endl;
        }

        for (int i = 0; i < numOfSubStr; i++) {
            bool flag = false;
            for (int j = 0; j < numOfSubDst; j++) {
                if (same(str, dst, nodesStr[i].st, nodesStr[i].end, nodesDst[j].st, nodesDst[j].end)) {
                    nodesDst[j].hasSame = true;
                    flag = true;
                    break;
                }
            }
            if (!flag) return false;
        }
        for (int j = 0; j < numOfSubDst; j++)
            if (!nodesDst[j].hasSame) return false;
    }
    return true;
}

int main() {
    int numOfCase;
    char str[MAXN] = {0}, dst[MAXN] = {0};
    std::cin >> numOfCase;
    while (numOfCase--) {
        std::cin >> str >> dst;
        bool flag = false;

        int strLen = 0, dstLen = 0;
        while (str[strLen] != 0) strLen++;
        while (dst[dstLen] != 0) dstLen++;

        if (DEBUG) std::cout << "len = " << strLen << " " << dstLen << std::endl;
        flag = same(str, dst, 0, strLen - 1, 0, dstLen - 1);

        if (flag) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}

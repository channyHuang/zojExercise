
#include <iostream>

#define MAXN 100005

char input[MAXN] = {0};

int main() {
    std::cin >> input;
    int len = 0;
    while (input[len] != 0) len++;
    int curSt = 0;
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (input[(curSt + j) % len] < input[(i + j) % len]) break;
            else if (input[(curSt + j) % len] > input[(i + j) % len]) {
                curSt = i;
                break;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        std::cout << input[(curSt + i) % len];
    }
    std::cout << std::endl;

    return 0;
}


/*

#include <iostream>

#define MAXN 100005
#define DEBUG 0

int index[26][MAXN] = {0};
char input[MAXN] = {0};

int main() {
    std::cin >> input;
    int len = 0;
    while (input[len] != 0) {
        index[input[len] - 'a'][++index[input[len] - 'a'][0]] = len;
        len++;
    }
    int i = 0, cmpPos = 1;
    for (i = 0; i < 26; i++) {
        if (index[i][0] > 0) break;
    }
    if (DEBUG) std::cout << "start car:" << char(i + 'a') << ", count = " << index[i][0] << std::endl;
    while (index[i][0] > 1) {
        if (cmpPos == len) break;
        for (int j = 2; j <= index[i][0]; j++) {
            if (input[(index[i][1] + cmpPos) % len] > input[(index[i][j] + cmpPos) % len])
                index[i][1] = index[i][j];
        }
        if (DEBUG) std::cout << "index[i][1] = " << index[i][1] << std::endl;
        int count = 1;
        for (int j = 2; j <= index[i][0]; j++) {
            if (input[(index[i][1] + cmpPos) % len] != input[(index[i][j] + cmpPos) % len]) continue;
            index[i][++count] = index[i][j];
        }
        index[i][0] = count;
        if (DEBUG) std::cout << "count = " << count << ", index[i][1] = " << index[i][1] << std::endl;
        cmpPos++;
    }

    int curSt = index[i][1];
    for (int i = 0; i < len; i++) {
        std::cout << input[(curSt + i) % len];
    }
    std::cout << std::endl;

    return 0;
}

*/
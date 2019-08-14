#include <iostream>

#define MAXN 100005
#define DEBUG 0

char input[MAXN] = {0};
int num[10] = {0};

int main() {
    std::cin >> input;
    int len = 0;
    while (input[len] != 0) {
        num[input[len] - '0']++;
        len++;
    }

    int st = 0, end = len - 1, i = 0;
    for (i = 9; i >= 0; i--) {
        if (num[i] == 0) continue;
        while (input[st] == i + '0') {
            st++;
            num[i]--;
            if (num[i] == 0) break;
        }
        if (num[i] == 0) continue;
        if (DEBUG) std::cout << "exchange number: " << i << std::endl;
        while (input[end] != i + '0') end--;
        input[end] = input[st];
        input[st] = i + '0';
        break;
    }

    if (i < 0) {
        char tmp = input[len - 2];
        input[len - 2] = input[len - 1];
        input[len - 1] = tmp;
    }

    for (int i = 0; i < len; i++) std::cout << input[i];
    std::cout << std::endl;

    return 0;
}

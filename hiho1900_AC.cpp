nclude <iostream>

#define MAXN 15

bool flag[MAXN] = {false};
int num;
int queue[MAXN] = {0};

void search(int num, int curNum) {
    if (curNum >= num) {
        for (int i = 0; i < num; i++) {
            if (i != 0) std::cout << " "; 
            std::cout << queue[i];
        }
        std::cout << std::endl;
    }
    
    if (curNum <= 0) return;
    for (int i = 1; i <= num; i++) {
        if (flag[i]) continue;
        if (i % 2 == queue[curNum - 1] % 2) continue;
        queue[curNum] = i;
        flag[i] = true;
        search(num, curNum + 1);
        flag[i] = false;
    }
}

int main() {
    std::cin >> num;
    for (int i = 1; i <= num; i++) {
        queue[0] = i;
        flag[i] = true;
        search(num, 1);
        flag[i] = false;
    }
    return 0;
}

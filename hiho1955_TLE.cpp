#include <iostream>

#define MAXN 100005

int numOfCard;
int cards[3][3][3] = {0};
int res = 0;

void search(int 

int main() {
	std::cin >> numOfCard;
	int val[3];
	for (int i = 0; i < numOfCard; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> val[j];
		}
		cards[val[0]][val[1]][val[2]]++;
	}
	
	


				for (int x = 0; x < 3; x++) {
					if (cards[i][x] == cards[j][x]) {
						if (cards[k][x] != cards[i][x]) break;
					}
					else {
						if (cards[k][x] == cards[i][x] || cards[k][x] == cards[j][x]) break;
					}
					if (x == 2) res++;
				}
			}
		}
	}
	std::cout << res << std::endl;
	return 0;
}

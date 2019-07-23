#include <iostream>

int main() {
	int totalRow, numOfBook;

	char bookSeat[5] = {0}, lastSeat[5];
	int curRow = 0, curCol = 0;
	int nextRow = 0, nextCol = 0;
	std::cin >> totalRow >> numOfBook;
	int res = totalRow * 3;
	for (int i = 0; i < numOfBook; i++) {
		lastSeat[0] = bookSeat[0];
		lastSeat[1] = bookSeat[1];
		curRow = nextRow;
		curCol = nextCol;

		std::cin >> bookSeat;
		nextRow = bookSeat[0] - '0';
		nextCol = bookSeat[1] - 'A';
		if (nextCol <= 2) nextCol = 1;
		else if (nextCol <= 6) nextCol = 2;
		else nextCol = 3;

		if (nextRow == curRow) {
			if (nextCol == curCol) {
				if (nextCol == 1 || nextCol == 3) continue;
				if (lastSeat[1] != 'D') continue;
				res--;
			} else {
				if (nextCol != 2) res--;
				else if (bookSeat[1] == 'D' || bookSeat[1] == 'G') continue;
				else res--;
			}
		} else {
			if (nextCol == 1 || nextCol == 3) res--;
			else {
				if (bookSeat[1] == 'D' || bookSeat[1] == 'G') continue;
				else res--;
			}
		}
	}
	std::cout << res << std::endl;
	return 0;
}

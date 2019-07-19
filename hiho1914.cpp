#include <iostream>

int main() {
	int totalRow, numOfBook;
	int res = totalRow * 3;
	char bookSeat[5];
	int curRow = 0, curCol = 0;
	int nextRow = 0, nextCol = 0;
	std::cin >> totalRow >> numOfBook;
	for (int i = 0; i < numOfBook; i++) {
		std::cin >> bookSeat;
		nextRow = bookSeat[0] - '0';
		nextCol = bookSeat[1] - 'A';
		if (nextCol <= 2) nextCol = 1;
		else if (nextCol <= 6) nextCol = 2;
		else nextCol = 3;

		if (nextRow == curRow) {
						
		
	

	}
	std::cout << res << std::endl;
	return 0;
}

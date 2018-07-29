#include <iostream>
#include <cstring>
#include <string>

char str[260];
int num[260];
int A = 0, B = 0;

int str2num(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return c - 'A' + 10;
	}
}

char num2str(int num) {
	if (num >= 0 && num <= 9) return num + '0';
	return num - 10 + 'A';
}

bool instruction(int &pos) {
	int code = num[pos];
	int address = 0;
	pos++;
	switch(code) {
	case 0:
		address = num[pos]* 16 + num[pos + 1];
		pos += 2;
		A = num[address];
		break;
	case 1:
		address = num[pos]* 16 + num[pos + 1];
		pos += 2;
		num[address] = A;
		str[address] = num2str(A);
		break;
	case 2: {
		int tmp = B;
		B = A;
		A = tmp;
		break;
	}
	case 3:
		A += B;
		B = A / 16;
		A %= 16;
		break;
	case 4:
		A++;
		A %= 16;
		break;
	case 5:
		A--;
		A = (A + 16) % 16;
		break;
	case 6:
		address = num[pos]* 16 + num[pos + 1];
		pos += 2;
		if (A == 0) {
			pos = address;
		}
		break;
	case 7:
		pos = num[pos]* 16 + num[pos + 1];
		break;
	case 8:
		return false;
	default:
		break;
	}
	return true;
}
		
int main() {
	while (1) {
		std::cin >> str[0];
		if (str[0] == '8') break;
		num[0] = str2num(str[0]);
		int i = 1;
		A = 0;
		B = 0;
		while (i < 256) {
			std::cin >> str[i];
			num[i] = str2num(str[i]);
			i++;
		}

		int pos = 0;
		while (1) {
			bool res = instruction(pos);
			if (!res) break;
		}
		for (int i = 0; i < 256; i++) {
			std::cout << str[i];
		}
		std::cout << std::endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>

int main() {
	std::string str = "hello";
	char *c = "how", *d = "are";
	std::strcat(c, d);
	std::cout << std::strlen(c) << std::endl;
	return 0;
}

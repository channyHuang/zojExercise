#include <iostream>
#include <cstring>
#include <string>

int main() {
	long n = 0;
       	long 	k = 0;
	while(n < 70) {
		k = (k<<1) + 1;
		std::cout << "n-k " << n << "-" << k << std::endl;
		n = n+1;
	}	
	return 0;
}

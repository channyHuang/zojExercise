#include <iostream>

#define MAXN 100005
int A[MAXN];
bool B[MAXN];

int main() {
	int numOfSeg;
	std::cin >> numOfSeg;
	for (int i = 0; i < numOfSeg; i++) {
		std::cin >> A[i];
	}
	bool bLastCharSame = false;
	bool bLastCharDif = false;
	long long nSame = 0, nDif = 0;
	for (int i = 0; i < numOfSeg; i++) {
		std::cin >> B[i];
		if (i == 0) {
			bLastCharSame = (A[i] % 2 ? B[0] : !B[0]);
			nSame += A[i] / 2;
			bLastCharDif = (A[i] % 2 ? !B[0] : B[0]);
			nDif += (A[i] / 2 + A[i] % 2);
		}
		else {
			if (B[i] == bLastCharSame) {
				bLastCharSame = (A[i] % 2 ? !B[i] : B[i]);
				nSame += (A[i] / 2 + A[i] % 2);
			}
			else {
				bLastCharSame = (A[i] % 2 ? B[i] : !B[i]);	
				nSame += A[i] / 2;	
			}
			if (B[i] == bLastCharDif) {
				bLastCharDif = (A[i] % 2 ? B[i] : !B[i]);
				nDif += A[i] / 2;
			}
			else {
				bLastCharDif = (A[i] % 2 ? !B[i] : B[i]);
				nDif += (A[i] / 2 + A[i] % 2);
			}
		}
	}

	std::cout << (nSame < nDif ? nSame : nDif) << std::endl;
	return 0;
}

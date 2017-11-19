#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

class BritishLength {
	float inch;
	
	public:
	
	
};

BritishLength::BritishLength() {
	inch = 0;
}

BritishLength::BritishLength(int ft) {
	inch = ft * 12;
}

BritishLength::BritishLength(int ft, float in) {
	inch = ft * 12 + in;
}





int main() {
	BritishLength b;
	int x;
	
	printf("neu..............0\n"
		   "add.........1\n"
		   "sub.....2\n"
		   "mult...3\n"
		   "div.......4\n");
	scanf("%d", &x);
	
	return 0;
}
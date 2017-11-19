#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 1

class BritishLength {
	float inch;
	
	public:
	int get_foot();
	float get_inch();
	float get_inch_part();
	BritishLength();
	BritishLength(int ft);
	BritishLength(int ft,float in);
};

BritishLength::BritishLength() {
	inch = 0;
	#if DEBUG
	printf("inch: %f\n", inch);
	#endif
}

BritishLength::BritishLength(int ft) {
	inch = ft * 12;
	#if DEBUG
	printf("inch: %f\n", inch);
	#endif
}

BritishLength::BritishLength(int ft, float in) {
	inch = ft * 12 + in;
	#if DEBUG
	printf("inch: %f\n", inch);
	#endif
}

int BritishLength::get_foot() {
	int ft;
	ft = inch / 12;
	return ft;
}

float BritishLength::get_inch() {
	float in;
	in = inch;
	return in;
}

float BritishLength::get_inch_part() {
	float in;
	in = inch % 12;
	return in;
}

int main() {
	BritishLength b();
	int ft;
	float in;
	ft = b.get_foot();
	in = b.get_inch();
	in = b.get_inch_part();
	
	return 0;
}
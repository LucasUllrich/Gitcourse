#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

class BritishLength {
	float in, in1;
	int ft, ft1;
	
	public:
	void neu();
	void inch();
};

void BritishLength::neu() {
	printf("foot: ");
	scanf("%d", &ft");
	printf("Inch\n");
	scanf("%f", &in);
	in = in + 12 * ft;
}

void BritishLength::addieren() {
	printf("foot: ");
	scanf("%d", &ft1");
	printf("Inch\n");
	scanf("%f", &in1);
	in1 = in1 + 12 * ft1;
	in = in + in1;
}

void BritishLength::subtrahieren() {
	printf("foot: ");
	scanf("%d", &ft1");
	printf("Inch\n");
	scanf("%f", &in1);
	in1 = in1 + 12 * ft1;
	in = in - in1;
}

void BritishLength::multiplizieren() {
		printf("foot: ");
	scanf("%d", &ft1");
	printf("Inch\n");
	scanf("%f", &in1);
	in1 = in1 + 12 * ft1;
	in = in * in1;
}



int main() {
	BritishLength b;
	int x;
	
	printf("neu..............0\n"
		   "addieren.........1\n"
		   "subtrahieren.....2\n"
		   "multiplizieren...3\n"
		   "dividieren.......4\n");
	scanf("%d", &x);
	
	switch(x) {
		case 0:		b.neu;				break;
		case 1:		b.addieren;			break;
		case 2:		b.subtrahieren;		break;
		case 3:		b.multiplizieren;	break;
		case 4:		b.dividieren;		break;
		default:
		printf("Kannst du nicht 0, 1, 2, 3 oder 4 eingeben???\n");
	}
	return 0;
}
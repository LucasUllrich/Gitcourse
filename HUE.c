#include <stdio.h>

int A[5];
int B[5];
int minA;
int maxA;
int minB;
float midA;
int sortflag = 0;

void rearagne(int c) {
	int hold = A[1 + c];
	printf("\n\nDebuginfo3:\n");
	printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
	A[1 + c] = A[c];
	printf("\n\nDebuginfo4:\n");
	printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
	A[c] = hold;
	printf("\n\nDebuginfo5:\n");
	printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
	sortflag = 1;
}

int main() {
	printf ("1 Wert: ");
	scanf ("%d", &A[0]);
	printf ("2 Wert: ");
	scanf ("%d", &A[1]);
	printf ("3 Wert: ");
	scanf ("%d", &A[2]);
	printf ("4 Wert: ");
	scanf ("%d", &A[3]);
	printf ("5 Wert: ");
	scanf ("%d", &A[4]);
	
	//****Evaluation of minimum
	minA = A[0]; 
	for (int c=1; c<5; c++) {
		if ( minA > A[c]){ 
			minA = A[c];
		}		
	}
	
	//****Evaluation of maximum
	maxA = A[0];
	for (int c=1; c<5; c++) {
		if ( maxA < A[c] ){
			maxA = A[c];
		}
	}
	
	//****Evaluation of median
	do {
		sortflag = 0;
		for(int c = 0; c < ((sizeof(A) / sizeof(A[0])) - 1); c++) {
			printf("\n\nDebuginfo1:\n");
			printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
			while(A[1 + c] < A[c]) {
				printf("\n\nDebuginfo2:\n");
				printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
				rearagne(c);
			}
		}
	} while (sortflag == 1);
	
	
	int x = (sizeof(A) / sizeof(A[0])) / 2;
	if ((sizeof(A) / sizeof(A[0])) % 2) {
		midA = A[x];
	}
	
	printf ("Minimum: %d\n", minA);
	printf ("Maximum: %d\n", maxA);
	printf ("Median: %d\n", A[x]);
	
	printf("\n\nDebuginfoE:\n");
	printf("A: %d, %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
	return 0;
}

#include <stdio.h>

int A[5];
int B[5];
int minA, minB;
int maxA;
int minB;
float midA;

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
	B[0] = minA;
	minB = 
	for(int c = 1; c < 5; c++) {
		for (int c = 1; c < 5; c++) {
			if ( minB > A[c]){ 
				minB = A[c];
			}
		}
		B[c] = A[];
	}
	
	printf("B: %d, %d , %d, %d, %d",
	B[0],
	B[1],
	B[2],
	B[3],
	B[4]);
	int x = (sizeof(B) / sizeof(B[0])) / 2;
	int size = sizeof(B) / sizeof(B[0]);
	printf("Size: %d\n", size);
	if (sizeof(B) %2) {
		midA = B[x];
	}
	
	printf ("Minimum: %d\n", minA);
	printf ("Maximum: %d\n", maxA);
	printf ("Median: %d", B[x]);
	return 0;
}

/*TrianglesArray:
	*) dynamisches Array
	*) Elemente einf�gen: add
	*) Ein Element auslesen: get(por)
	*) Ein Element �ndern: set(t, por)
	   das alte Element soll zur�ckgegeben werden
	*) Ein Element l�schen: del(pos)
	   das gel�schte Element soll zur�ckgegeben werden
	*) Ein Element einf�gen add(t, pos)
	*) Die Anzahl der Elemente ermitteln: size()


TrianlesArray ta;
Triangle *t, *t;

t.add(new Triangle("bla", ,,,));

t = ta.get(0);
t2 = ta.set(new Triangle("hugo", 3,4,5));*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class TriangleArray{
	char name[100];
	float a, b, c;

	public:
	void einlesen();
};

void TriangleArray::einlesen() {

	printf("Name: ");
	scanf("%s", name);
	printf("Triangle a: ");
	scanf("%f", &a);
	printf("Triangle b: ");
	scanf("%f", &b);
	printf("Triangle c: ");
	scanf("%f", &c);
}

class Triangles {
	public:
	int cnt;
	TriangleArray *triangle[100];
	char name[100];
	float a,b,c;
	void einlesen();
	void auslesen();
	void aendern();
	void neu();
	void loeschen();
};


void Triangles::einlesen() {

	printf("Name: ");
	scanf("%s", name);
	printf("Triangle a: ");
	scanf("%f", &a);
	printf("Triangle b: ");
	scanf("%f", &b);
	printf("Triangle c: ");
	scanf("%f", &c);
}


void Triangles::neu() {
	triangle[cnt] = new TriangleArray;
	triangle[cnt]->einlesen();
	cnt++;
}

void Triangles::aendern() {
	int x;

	printf("Was soll geandert werden: ");
	scanf("%d", &x);

	triangle[x-1]->einlesen;
}

void Triangles::loeschen() {
	int x;

	printf("Was soll geloesht werden. ");
	scanf("%d", &x);

	delete triangle[x-1];
}

void Triangles::auslesen() {
	int i;
	for(i = 0; i <= d.cnt; i++) {
		printf("Dreieck %s a=%f b=%f c=%f", triangle[cnt].name, a, b, c);
	}
}

int main() {
	Triangles d;
	int x;

	printf("einlesen.......0\n"
		   "aendern........1\n"
		   "loeschen.......2\n"
		   "auslesen.......3\n");
	scanf("%d", &x);

	switch(auswahl) {
		case 0: 		d.neu;			break;
		case 1:         d.aendern;      break;
		case 2:			d.loeschen();	break;
		case 3:			d.auslesen();	break;
        default:
		printf("Kannst du nicht 0, 1, 2 oder 3 eingeben???\n");
    }
}

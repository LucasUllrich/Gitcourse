// Dreiecksklasse mll 2017-10-03 f�r 3AM
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXTRIANGLES 20



class Triangle {
  char name[20];
  float a, b, c;
  public:
    ~Triangle() {}
    Triangle(char *name, float a, float b, float c);
    Triangle(char *name, float a);
    Triangle();
	float area();
    void init(char *name, float a, float b, float c);
	void write(FILE *out);
    void Eingabe();
    void Ausgabe() {
		printf("Dreieck %s a=%f b=%f c=%f area=%f\n", name, a, b, c, area());
    }

	int istDreieck();
};

void Triangle::write(FILE *out) {
  fprintf(out,"%s %f %f %f\n",name,a,b,c);
  return;
}

int Triangle::istDreieck() {
	if (a < 0 || b < 0 || c < 0||
		a+b < c || a+c < b || b+c < a) {
		return 0;
	}

	if (a+b == c || a+c == b || b+c == a) {
		return 2;
	}
	return 1;
}

void Triangle::Eingabe() {
  printf("Dreieck Name ? " );
  scanf("%s",name); // name ist ein char[] daher schon ein Zeiger!
  printf("Seite a ? ");
  scanf("%f", &a);
  printf("Seite b ? ");
  scanf("%f", &b);
  printf("Seite c ? ");
  scanf("%f", &c);
}

void Triangle::init(char *name, float a, float b, float c) {

  strcpy(this->name, name);
  this->a = a;
  this->b = b;
  this->c = c;

  return;
}

Triangle::Triangle() {
  strcpy(name,"");
  a=b=c=0.;
}

Triangle::Triangle(char *name, float a, float b, float c) {
  init(name, a, b, c);
}

Triangle::Triangle(char *name, float a) {
  init(name, a, a, a);
}

float Triangle::area() {
	if (istDreieck()) {
		float s = (a+b+c)/2;

		return aqrt(s * (s-a) * (s-b) * (s-c));
	}
	return 0;
}
//#####################################################
class Triangles {
  public:
  int cnt;
  Triangle *t[MAXTRIANGLES];
  Triangles();
  ~Triangles();

  void ausgabe();
  void clear();
  void add();
  void update();
};

Triangles::Triangles() {
  FILE *in;
  char line[100];
  int n;
  char name[20];
  float a,b,c;
  cnt = 0;
  in=fopen("triangles.dat","r");
  if(in) {
    printf("Im Konstruktor Triangels, Datei ge�ffnet!\n");
    while(fgets(line,sizeof line,in)) {
	printf("Zeile gelesen: %s\n",line);
	n=sscanf(line,"%s %f %f %f",name,&a,&b,&c);
	printf("n= %d\n",n);
	if(n==4) {
	    t[cnt] = new Triangle(name,a,b,c);
		if (t[cnt]->istDreieck() == 1) {
			cnt++;
		}
		else {
			delete t[cnt];
		}
	  }
	}
	fclose(in);
  }

}

Triangles::~Triangles() {
  FILE *out;
  out=fopen("triangles.dat","w");
  // Fehlerbehandlung ???
  for(int i=0;i<cnt;i++) {
    t[i]->write(out);
	   delete t[i];       // Speicher freigeben
  }
  fclose(out);
}

void Triangles::eingabe() {
	while(1) {
		printf("Dreieck Name ?");
		scanf("%s", name);
		printf("Seite a ? ");
		scanf("%f", &a);
		printf("Seite b ");
		scanf("%f", &b);
		printf("Seite c ");
		scanf("%f", &c);

		if (istDreieck() == 1) {
			Ausgabe();
		}
	}
}

void Triangles::ausgabe(){
	for (int i=0;i < cnt; i++) {
	    printf("%2d: ", i+1);
		t[i]->Ausgabe();
	}
}

void Triangles::clear() {
	for (int i=0; i < cnt; i++) {
		delete t[i];
	}
	cnt=0;
}

void Triangles::add() {
	t[d.cnt] = new Triangle;
    t[d.cnt]->eingabe();
    d.cnt++;
}

void Triangles::update() {
	int n;
	ausgabe();
	printf("Welches Dreieck soll gaendert werden? ");
	while (scanf("%d", &n) != 1) {
		fflush(stdin);
	}

	if ( n == 0) {
		return;
	}

	if (n <= 0 || n > cnt) {
		printf("ERROR: Ungueltige Dreiecks-Numme");
		return;
	}

	t[n-1]->eingabe();
}

int main() {
  int run=1, auswahl;

  Triangles d;

  if(d.cnt) {
    printf("Es wurden %d Dreiecke geladen:\n",d.cnt);
    for(int i=0;i<cnt;i++) {
     t[i]->Ausgabe();
    }
  }
  else {
    printf("Es wurden keine Dreiecke geladen!\n");
  }

  while(run) {
    printf("Alle loeschen      .... 1\n"
		   "Dreieck hinzufuegen ... 2\n"
           "Ausgabe            .... 3\n"
           "Ende     .... 0\n"
           "Auswahl ? ");
    scanf("%d",&auswahl);
    switch(auswahl) {
		case 0: 		d.eingabe;		break;
		case 1:         d.ausgabe;      break;
		case 2;			d.add();		break;
		case 3:			d.ausgabe();	break;
		case 4 ; 		d.update ();    break;
         default:
			printf("Kannst du nicht 0, 1 oder 2 eingeben???\n");
    }
  }
}

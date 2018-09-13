
/*W funkcji main() zdefiniowa� zmienn� lokaln� okre�laj�c� tablic� liczb typu 
float o rozmiarze K, gdzie K jest sta�� r�wn� 95. Opracowa� funkcje, kt�re jako
 argument wej�ciowy maj� mie� przekazywan� tablic�:

   1. inicjuj�c� tablic� losowymi liczbami rzeczywistymi nale��cymi do przedzia�u [-1.2 2.3);
   2. wyprowadzaj�c� zawarto�� tablicy na ekran, po 10 w wierszu;
   3. zwracaj�ca najwi�ksz� liczb� z tablicy spo�r�d mniejszych ni� 0;

Wykorzysta� funkcje w programie. */

#include <stdio.h>
#include <stdlib.h>

 
 const int K = 95; 
 
void init(double *a)
 {
int i;

  srand ( time(NULL) ); 
  for (i=0;i<K;i++) a[i]=(double) (rand()%230000)/10000-1,2 ;
  printf("\n TABLICA ZOSTALA WYPELNIONA WARTOSCIAMI Z ZAKRESU [-1.2 2.3)\n");
  printf(" DO CZTERECH MIEJSC PO PRZECINKU\n");
 }

void show(double *a)
{ 
int i;

 printf("\n ZAWARTOSC TABLICY: \n\n"); 
 for (i=0;i<K;i++)
  { 
   printf(" %.3f ",a[i]);
   if (i%10==9) printf("\n");
  }
}

double naj(double *a)
{
int i=0;
double q=1;

 while(q>0) { q=a[i]; i++;}  //szukanie pierwszej mniejszej od 0
 for (i=i;i<K;i++)if (a[i]<0 && a[i]>q) q=a[i]; //szukanie liniowe
 return q;
}

int main(void)
{  
int i;    
double z[K];

 init(z);  //inicjuje tablice losowymi liczbami
 show(z);  //wyswietla tablica
 printf("\n\n NAJWIEKSZA MNIEJSZA OD 0 TO: %f",naj(z));
 getch();	
 return 0;
}


/*  Zmodyfikuj zadnie 1A tak, aby operowaæ na dwuwymiarowej tablicy (MxN). 
Opracowane funkcje maj± jako jedyny argument mieæ przekazywany wska¼nik do 
liczby typu double, wewn±trz funkcji nale¿y operowaæ na wska¼nikach a nie na 
operatorze []. W programie nie ma byæ ostrze¿eñ (konieczne jest rzutowanie 
typów podczas wywo³añ funkcji).  */

#include <stdio.h>
#include <stdlib.h>
 
 const int M = 10; 
 const int N = 10;
 
void init(double *a)
{
int i;

 srand ( time(NULL) ); 
 for (i=0;i<M*N;i++) (double)*(a+i)=(double) (rand()%230000)/10000-1.2 ;
 printf("\n TABLICA ZOSTALA WYPELNIONA WARTOSCIAMI Z ZAKRESU [-1.2 2.3)\n");
 printf(" DO CZTERECH MIEJSC PO PRZECINKU\n");
 }

void show(double *a)
{ 
int i;

 printf("\n ZAWARTOSC TABLICY: \n\n"); 
 for (i=0;i<M*N;i++)
 { 
  printf(" %.3f ",(double)*(a+i));
  if (i%10==9) printf("\n");
  //if (i%400==0) getch();
 }
}

double naj(double *a)
{
int i=0;
double q=1;

 while(q>0) { q=a[i]; i++;}  //szukanie pierwszej mniejszej od 0
 for (i=i;i<M*N;i++)if ((double)*(a+i)<0 && (double)*(a+i)>q) q=(double)*(a+i); //szukanie liniowe
 return q;
}

int main(void)
{  
int i;    
double z[M][N];

 init(*z);  //inicjuje tablice losowymi liczbami
 show(*z);  //wyswietla tablica
 printf("\n\n NAJWIEKSZA MNIEJSZA OD 0 TO: %f",naj(*z));
 getch();	
 return 0;
}

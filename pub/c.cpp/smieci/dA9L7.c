
/*Zadeklarowaæ typ wskazuj±cy (wska¼nik) na:
a) zmienn± typu int;
b) zmienn± typu double;
c ) tablicê liczb typu int o rozmiarze N, gdzie N ? sta³a;
d ) rekord typu towar (typedef struct { char nazwa[40]; unsigned ilosc; long id; } towar;)
W programie g³ównym utworzyæ zmienne dynamiczne odpowiadaj±ce zadeklarowanym 
typom. Zainicjowaæ utworzone zmienne losowymi warto¶ciami lub warto¶ciami 
wprowadzanymi z klawiatury. Wyprowadziæ zawarto¶æ zmiennych na ekran. Przed 
zakoñczeniem programu zwolniæ pamiêæ.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{ 
        char nazwa[40]; 
        unsigned ilosc; 
        long id; 
} towar;

int main(void)
{ 
  const N = 5;
  int i;
  
  int* a;
  double* b;
  int* c;
  towar* d;
  
  a=malloc(sizeof(int));
  b=malloc(sizeof(double));
  c=malloc(sizeof(int)*N);
  d=malloc(sizeof(towar));
  
  srand( (unsigned)time( NULL ) );
  
  *a=rand()%45324;
  *b=rand()%23532/234.0;
  for (i=0;i<N;i++) c[i]=rand()%32423;
  for (i=0;i<25;i++) d->nazwa[i]=65+rand()%24;
  d->ilosc=rand()%4324;
  d->id=rand()%4234423;
  
  printf("a= %d\n",*a);
  printf("b= %lf\n",*b);
  printf("c=");
  for (i=0;i<N;i++) printf(" %d ",c[i]);
  printf("\n");
  printf("d= nazwa: %s \n   ilosc: %d \n   ID: %ld \n",d->nazwa,d->ilosc,d->id);
  
  free(a);
  free(b);
  free(c);
  free(d);
  
  getch();
  return 0;
}

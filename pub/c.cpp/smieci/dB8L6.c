
/* Zdefiniowaæ tablicê kwadratow± liczb ca³kowitych typu unsigned i zainicjowaæ 
j± losowymi warto¶ciami nale¿±cymi do przedzia³u [0, 2). Napisaæ funkcje, które 
potrafi±:
a) Wyprowadziæ zawarto¶æ tablicy wierszami na ekran.
b) Obliczyæ sumê elementów tablicy i wyprowadziæ otrzyman± warto¶æ na ekran.
c) Obliczyæ sumê elementów na przek±tnych tablicy (s± dwie przek±tne, dwie 
funkcje)
Operacje wewn±trz funkcji maj± siê odbywaæ poprzez wska¼niki a nie operator [], 
tablica ma byæ przekazywana jako wska¼nik na pierwszy element (float *tab).*/

#include <stdio.h>
#include <stdlib.h>

const M = 10;

void a(unsigned*);
void b(unsigned*);
void c1(unsigned* t);
void c2(unsigned* t);

int main(void)
{ 
    unsigned tab[M][M];

     srand ( time(NULL) ); 
     int i;
     for (i=0;i<M*M;i++)
          (unsigned)*(*tab+i)=rand()%2; 
    
  a(*tab);
  b(*tab);
  c1(*tab);
  c2(*tab);
  
  getch();	
  return 0;
}

void a(unsigned* t)
{
 int m,n;

 printf("Wylosowana tablica: \n\n");
 for (m=0;m<M;m++)
 {
  for (n=0;n<M;n++)
   printf("%d",(unsigned)*(t+(M*m)+n));
  printf("\n");
 }
}

void b(unsigned* t)
{
     int i,s=0;
     for (i=0;i<M*M;i++)
      s+=(unsigned)*(t+i);
     printf("\n\nSuma elementow tablicy to: %d",s);
}

void c1(unsigned* t)
{
     int i,j,s=0;
     for (i=0;i<M;i++)
      for (j=0;j<M;j++)
       if (i==j)
        s+=(unsigned)*(t+(i*M)+j);
     printf("\n\nSuma elementow na 1 przekatnej tablicy to: %d",s);
}

void c2(unsigned* t)
{
     int i,j,s=0;
     for (i=0;i<M;i++)
      for (j=0;j<M;j++)
       if (i+j+2==M)
        s+=(unsigned)*(t+(i*M)+j);
     printf("\n\nSuma elementow na 2 przekatnej tablicy to: %d",s);
}

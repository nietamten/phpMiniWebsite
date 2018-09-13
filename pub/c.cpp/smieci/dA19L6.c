
/*W funkcji main() zdefiniowaæ zmienn± lokaln± okre¶laj±c± tablicê liczb typu 
double o rozmiarze M, gdzie M jest sta³±. Opracowaæ funkcje, które jako argument 
wej¶ciowy maj± mieæ przekazywan± tablicê:
a) inicjuj±c± tablicê losowymi liczbami rzeczywistymi nale¿±cymi do przedzia³u 
[-7, -1.3);
b) wyprowadzaj±c± zawarto¶æ tablicy na ekran;
c) obliczaj±c± ilo¶æ elementów wiêkszych ni¿ -2.5 i mniejszych ni¿ -1.5 ;
Wykorzystaæ funkcje w programie.*/

#include <stdio.h>
#include <stdlib.h>

const M = 5;

void a(double*);
void b(double*);
int c(double *);

int main(void)
{ 
    double tab[M];
    
  a(tab);
  b(tab);
printf("\n\n%d",c(tab));
  getch();	
  return 0;
}

void a(double t[])
{
     srand ( time(NULL) ); 
     int i;
     for (i=0;i<M;i++)
          t[i]= ( (double)(((rand()%57) /10))+ ((double)(rand()%10001)/10000) )-7; 
}

void b(double t[])
{
     int i;
     for (i=0;i<M;i++) printf(" %g ",t[i]);
}

int c(double t[])
{
      int i,j=0;
     for (i=0;i<M;i++)  if ( (t[i]>(-2.5)) && (t[i]<(-1.5))) j++; 
 return j;
}

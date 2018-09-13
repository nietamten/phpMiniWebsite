
/*W funkcji main() zdefiniowaæ zmienn± lokaln± okre¶laj±c± tablicê liczb typu 
int o rozmiarze (KxN), gdzie K i N s± sta³ymi. Opracowaæ funkcje, które jako 
argument wej¶ciowy maj± mieæ przekazywan± tablicê:
a) inicjuj±c± tablicê losowymi liczbami ca³kowitymi nale¿±cymi do przedzia³u 
[2,87);
b) wyprowadzaj±c± zawarto¶æ tablicy na ekran;
c) obliczaj±c± sumê elementów podzielnych przez 3;
Wykorzystaæ funkcje w programie. Opracowane funkcje maj± mieæ jako jedyny 
argument przekazywany wska¼nik do liczby typu int. W funkcji z punktu b) nale¿y 
wprowadziæ tablicê wierszami (po koñcu wiersza znak nowej linii), a w c) nale¿y 
sumowaæ po wszystkich wierszach, ale tylko po nieparzystych kolumnach 
(oczywi¶cie i tylko po liczbach podzielnych przez 3). W programie nie ma byæ 
ostrze¿eñ (konieczne jest rzutowanie typów podczas wywo³añ funkcji).*/

#include <stdio.h>
#include <stdlib.h>

const M = 5; //wiersze
const N = 10; //kolumny

void a(int*);
void b(int*);
void c(int* t);

int main(void)
{ 
    int tab[M][N];
    
  a(*tab);
  b(*tab);
  c(*tab);
  
  getch();	
  return 0;
}

void a(int* t)
{
 int m,n;

     srand ( time(NULL) ); 
     int i;
     for (i=0;i<M*N;i++)
          *(t+i)=(rand()%86)+2;
}


void b(int* t)
{
 int m,n;

 printf("Wylosowana tablica: \n\n");
 for (m=0;m<M;m++)
 {
  for (n=0;n<N;n++)
   printf(" %3d ",*(t+(N*m)+n));
  printf("\n");
 }
} 

void c(int* t)
{
 int m,n,s=0;
 for (m=0;m<M;m++)
  for (n=0;n<N;n++)
  if ( (int)*(t+(N*m)+n)%3 == 0 && (n+1)%2==1 )s+=(int)*(t+(N*m)+n);//kolumny licze od 1 nie od 0
  printf("\n\nSuma elementow podzielnych przez 3 z nieparzystych kolumn to %d",s); 
}


/*Zadeklarowa� typ tablicowy typedef double tx[N][2]. Opracowa� funkcj�, kt�ra 
wyznacza warto�ci dowolnej funkcji w przedziale [min, max] dla N punkt�w postaci 
xi = min + i*d, gdzie d=(max-min) / (N-1) oraz i=0,1,...,N-1 (N - sta�a). 
Obliczone elementy xi, f(xi) powinny by� zapami�tane w tablicy T typu tx w 
spos�b nast�puj�cy: T[i][0] = xi oraz T[i][1] = f(xi). Funkcja obliczaj�c� ma 
by�a uniwersalna, pozwala� ma na podanie jako argument dowolnej funkcji 
wyliczaj�cej warto�ci wpisywane do tablicy T. Prototyp funkcji: 
void oblicz(double min, double max, int n, tx T,wska�nik funkcji). 
W programie g��wnym wykona� obliczenia dla funkcji sin i cos w przedziale [-pi/2, pi/2].*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 50 

typedef double tx[N][2];

void oblicz(double min, double max, int n, tx T,double(*wsk)(const void*))
{
}

int main(void)
{ 
   
  getch();
  return 0;
}

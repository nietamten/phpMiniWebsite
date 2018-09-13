/*-----------------------------------------------------*/
/*Sprawd¼ czy trzy zadane liczby zmiennoprezcinkowe a,b,c wprowadzone z kalawiatury s± d³go¶ciami boków trójk±ta. 
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//skopiowane z zadania 23 z A, bo mi sie nie chcialo :P
int b,c;
float a[3],d;
printf("Podaj kolejno 3 wartosci\n");  
for (b=0;b<3;b++)                       
scanf("%f",&a[b]); //pobieranie liczb

//babelki bo mniej pisania niz z ifami ale wiecej o 3 zmienne
// sortowanie aby otrzymac 2 najmniejsze
for (b=0;b<3;b++) for (c=0;c<2;c++) if (a[c]>a[c+1]) 
{d=a[c]; a[c]=a[c+1]; a[c+1]=d;} 


//sprawdzamy czy suma mniejszych wartosci nie jest mniejsza od najwiekszej
if (a[0]+a[1]<a[2]) 
printf("podane wartosci NIE moga byc dlugosciami bokow trojkata");
else
printf("podane wartosci moga byc bokami trojkata");


   getch();
   return 0;
}
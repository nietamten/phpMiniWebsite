/*Napisz program wczytuj±cy trzy liczby ca³kowite i drukuj±cy na ekranie 
(jako rezultat) te liczby w kolejno¶ci rosn±cej. 
*/

#include <stdio.h>
#include <conio.h>

int main (void)
{
int a[2],b,c,d;
printf("Podaj kolejno wartosci 3 liczby\n");
for (b=0;b<3;b++)
scanf("%d",&a[b]);
for (b=0;b<3;b++) for (c=0;c<2;c++) if (a[c]>a[c+1]) //babelki bo mniej pisania
{d=a[c]; a[c]=a[c+1]; a[c+1]=d;} //niz z ifami ale wiecej o 3 zmienne
printf("podane liczby w kolejnosci rosnacej to:\n");
for (b=0;b<3;b++)
printf("%d\n",a[b]);

   getch();
   return 0;
}
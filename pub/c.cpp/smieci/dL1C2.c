/*Napisz program który drukuje na ekranie "Na zewn±trz", "Wewn±trz", 
"Na krawêdzi" w zale¿no¶ci od tego czy punkt na p³aszczy¿nie (x,y) o 
wprowadzonych przez u¿ytkownika parametrach le¿y wewn±trz prostok±ta 
(opisanego przez dolny lewy róg - punkt oraz szeroko¶æ i wysoko¶æ prostok±ta).
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
int x,y,x1,y1,sz,w;
printf("Podaj wspolzedne dolnego lewego rogu prostokata \n\n x= ");
scanf("%d",&x);
printf("\n y= ");
scanf("%d",&y);
printf("\nPodaj szerokosc prostokata\n\n szerokosc= ");
scanf("%d",&sz);
printf("\nPodaj wysokosc prostokata\n\n wysokosc= ");
scanf("%d",&w);
printf("\nPodaj wspolzedne punktu\n\n x= ");
scanf("%d",&x1);
printf("\n y= ");
scanf("%d",&y1);

if ( ((x1==x | x1==x+sz)&(y1>=y & y1<=y+w) ) | (y1==y | y1==y+w)&(x1>=x & x<=x+sz) )
printf("\n\n Podany punkt lezy na krawedzi prostokatu");

if ( (x1>x & x1<x+sz)&(y1>y & y1<y+w) )
printf("\n\n Podany punkt wewnatrz prostokatu");
   getch();
   return 0;
}

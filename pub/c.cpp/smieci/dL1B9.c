/*# Napisz program kt�ry drukuje na ekranie "Na zewn�trz", "Wewn�trz", "Na krawa�dzi" w zale�no�ci od tego czy punkt na p�aszczy�nie (x,y) o wprowadzonych przez u�ytkownika parametrach le�y wewn�trz okr�gu (opisanego przez �rodek i promie�) czy nie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
float x,y,r,px,py,od; 
int a;
printf("Podaj wspolrzedne srodka okregu\n");
printf("\nx= ");
scanf("%f",&x);
printf("\ny= ");
scanf("%f",&y);
printf("\nPodaj dlugosc promienia \n\nr= ");
scanf("%f",&r);
printf("\nPodaj wspolzedne badanego punktu\n");
printf("\nx= ");
scanf("%f",&px);
printf("\ny= ");
scanf("%f",&py);
printf("\n\n");
//obliczam odleglosc badanego punktu od srodka okregu
//jesli bedzie wieksza niz r punkt bedzie poza okregiem
//jezeli rowna bedzie na krawedzi

od=hypot(px-x,py-y);
if (od>r) printf("punkt znajduje sie poza okregiem");
if (od==r) printf("punkt znajduje sie na krawedzi okregu");
if (od<r) printf("punkt znajduje sie w okregu");
   getch();
   return 0;
}
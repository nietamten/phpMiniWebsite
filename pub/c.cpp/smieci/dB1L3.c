/* # Napisz funckj� wyznaczaj�c� wysoko�� sp�aty miesi�cznej s, dla pewnej 
kwoty kredytu k, gdy jest okre�lony miesi�czny procent p op�aty od sumy 
zad�u�enia, tj. zaci�gni�tego i jeszcze nie sp�aconego kredytu (odsetki), 
przy za�o�eniu, �e sp�ata miesi�czna ma by� sta�a i okre�lony jest czas 
sp�acania kredytu, tj. liczba miesi�cy lub liczba rat n. Obliczenia wykona� 
korzystaj�c ze wzoru:
*/


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


//program realizuje wzor ale nie wydaje mi siezeby on mial cos wspolnego
//z wyznaczaniem wysokosci miesiecznej raty
float splata (float k , float p , int n)
{float s;
s= k*( (p*pow(p+1.0,n))/(pow(1.0+p,n)-1.0)  );
      return s;
      }
      
int main(void)
{ 
    float a,b;
    int c;
printf("podaj kwote gredytu (k) \n");
scanf("%f",&a);
printf("podaj procent (p) \n");
scanf("%f",&b);
printf("podaj liczbe rat (n) \n");
scanf("%d",&c);
printf("\nwysokosc raty (s) to: %f",splata(a,b,c));
getch();
}

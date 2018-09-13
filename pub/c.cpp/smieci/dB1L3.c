/* # Napisz funckjê wyznaczaj±c± wysoko¶æ sp³aty miesiêcznej s, dla pewnej 
kwoty kredytu k, gdy jest okre¶lony miesiêczny procent p op³aty od sumy 
zad³u¿enia, tj. zaci±gniêtego i jeszcze nie sp³aconego kredytu (odsetki), 
przy za³o¿eniu, ¿e sp³ata miesiêczna ma byæ sta³a i okre¶lony jest czas 
sp³acania kredytu, tj. liczba miesiêcy lub liczba rat n. Obliczenia wykonaæ 
korzystaj±c ze wzoru:
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

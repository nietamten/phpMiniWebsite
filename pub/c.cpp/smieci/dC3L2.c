/* 
Oblicz sumy sp�at okre�lonej kwoty kredytu, gdy jest okre�lony miesi�czny 
procent op�aty od sumy zad�u�enia, tj. zaci�gni�tego i jeszcze nie sp�aconego 
kredytu (odsetki), przy nast�puj�cych warunkach sp�at:
- w ka�dym miesi�cu wp�aca si� okre�lon� sta�� rat�, zmniejszaj�c� kwot� 
zad�u�enia i odsetki od aktualnego zad�u�enia; Okres sp�at zale�y od kwoty 
kredytu i wielko�ci sta�ej raty.
- jest okre�lona sp�ata sta�a, na kt�r� sk�ada si� sp�ata odsetek i rata 
zmienna, pozosta�a ze sp�aty sta�ej po odj�ciu odsetek. Okres sp�at wynika z 
kwoty kredytu i sp�aty sta�ej.
Nale�y poda� miesi�czne sumy sp�at w rozbiciu na rat� i odsetki oraz 
dotychczasow� warto�� kwoty zwr�conej do banku ��cznie z warto�ci� sp�acan� w 
tym miesi�cu, dla wszystkich miesi�cy w okresie sp�acania kredytu.
*/

void zlykoniec (void)
{
printf("podano zle dane program zostanie zakonczony");
getch();
exit(1);
};

#include <conio.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
float pr, zad , sr, od,s=0;
int l=0;
char q;

printf ("Wartosc zadluzenia: ");
scanf("%f",&zad);
printf ("Procent oplaty od sumy zadluzenia: ");
scanf("%f",&pr);
printf ("Wartosc stalej raty: ");
scanf("%f",&sr);

if(zad<0) zlykoniec();
if(pr>100||pr<0) zlykoniec();
if(  ((pr/100)* zad ) > sr  ) zlykoniec();

printf("\n\nmiesiac         aktualne      odsetki      rata        suma \n");
printf("                zadluzenie                 zmienna      splat\n");

do{
l++;
od=(pr/100)*zad;
s+=sr;
zad+=od;
zad-=sr;  
printf("\n  %d          %f       %f    %f     %f\n",l,zad,od, sr-od, s);
getch();
  }while(zad > 0);

 getch();
 return 0;
  
}
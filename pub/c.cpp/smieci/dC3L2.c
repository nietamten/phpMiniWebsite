/* 
Oblicz sumy sp³at okre¶lonej kwoty kredytu, gdy jest okre¶lony miesiêczny 
procent op³aty od sumy zad³u¿enia, tj. zaci±gniêtego i jeszcze nie sp³aconego 
kredytu (odsetki), przy nastêpuj±cych warunkach sp³at:
- w ka¿dym miesi±cu wp³aca siê okre¶lon± sta³± ratê, zmniejszaj±c± kwotê 
zad³u¿enia i odsetki od aktualnego zad³u¿enia; Okres sp³at zale¿y od kwoty 
kredytu i wielko¶ci sta³ej raty.
- jest okre¶lona sp³ata sta³a, na któr± sk³ada siê sp³ata odsetek i rata 
zmienna, pozosta³a ze sp³aty sta³ej po odjêciu odsetek. Okres sp³at wynika z 
kwoty kredytu i sp³aty sta³ej.
Nale¿y podaæ miesiêczne sumy sp³at w rozbiciu na ratê i odsetki oraz 
dotychczasow± warto¶æ kwoty zwróconej do banku ³±cznie z warto¶ci± sp³acan± w 
tym miesi±cu, dla wszystkich miesiêcy w okresie sp³acania kredytu.
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
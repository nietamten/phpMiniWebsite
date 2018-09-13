/*Napisz funkcjê, który konwertujê wprowadzan± liczbê ca³kowit± na postaæ 
szesnastkow±. Nie korzystaj z tablic, ³añcuchów znaków. Wykorzytaj rekurencjê 
do przedstawaienia wyniku na ekranie (w poprawnej kolejno¶ci cyfr).*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int bc( int n)
{
if (n>0)
bc(n/16);
if ( (n%16<10) && (n!=0) )
printf (" %d ",n%16); else
switch (n%16){
       case 10:printf(" A ");break;
       case 11:printf(" B ");break;
       case 12:printf(" C ");break;
       case 13:printf(" D ");break;
       case 14:printf(" E ");break;
       case 15:printf(" F ");break;
       }
}
      
int main(void)
{ 
int c;
printf("podaj liczbe \n");
scanf("%d",&c);
if (c!=0)
bc(c); else printf(" 0");
getch();
}

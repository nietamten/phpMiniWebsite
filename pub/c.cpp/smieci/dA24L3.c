/* Napisaæ funkcjê drukuj±c± na ekranie zadan± liczbê 
rzeczywist± (jako argument funckji) z zadan± liczb± miejsc
 po przecinku i przed przecinkiem (po przecinku: rok_urodzenia 
% 7, przed_przecinkiem=miesisac_urodzenie).
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void ciag(int a,int b, float x)
{ 
char q[20]="%",r[20]="";
itoa(a,r,10);
strcat(q,r);
strcat(q,".");
itoa(b,r,10);
strcat(q,r);
strcat(q,"f");
printf (q,x);
};

int main(void)
{ int a,b;
float c;
printf("podaj ilosc miejsc przed przecinkiem\n");
scanf("%d",&a);
printf("podaj ilosc miejsc po przecinku\n");
scanf("%d",&b);
printf("podaj liczbe zmiennoprzecinkowa do wyswietlenia\n");
scanf("%f",&c);
printf("\n\n");
ciag(a,b,c);
getch();
}


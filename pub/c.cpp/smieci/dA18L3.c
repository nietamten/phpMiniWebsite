/* Wczytaæ z klawiatury liczbê ca³kowit± typu int, a nastêpnie wyprowadziæ na ekran
w formacie dziesiêtnym, szesnastkowym i ósemkowym. Liczby wyprowadzaæ na 10 polach 
(napisaæ w³asn± funkcjê).
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void ciag(int x)
{ 
printf ("\n dziesietnie:\n %10d",x);
printf ("\n osemkowo:\n %10o",x);
printf ("\n szesnastkowo:\n %10X",x);
};

int main(void)
{ int a;
printf("liczbe do wyswietlenia\n");
scanf("%d",&a);
ciag(a);
getch();
}
/* Wczyta� z klawiatury liczb� ca�kowit� typu int, a nast�pnie wyprowadzi� na ekran
w formacie dziesi�tnym, szesnastkowym i �semkowym. Liczby wyprowadza� na 10 polach 
(napisa� w�asn� funkcj�).
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
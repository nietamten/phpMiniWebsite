
/*Opracowaæ program, który utworzy dynamicznie tablicê liczb ca³kowitych o rozmiarze
n wczytywanym z klawiatury. Nastêpnie wczytaæ z klawiatury n liczb. Rozszerzyæ 
tablicê o 2 elementy. Policzyæ warto¶æ maksymaln± i minimaln± i wpisaæ je do rozszerzonej tablicy.
Wyprowadziæ zawarto¶æ tablicy w tym tak¿e znalezione minimum i maksimum, 
na ekran. Przed zakoñczeniem programu zwolniæ pamiêæ przydzielon±.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{ 
    int n,*tab,i,min,max;
    
    printf("podaj n\n");
    scanf("%d",&n);
    tab=malloc(sizeof(int)*n);
    for  (i=0;i<n;i++) 
    {
     printf("podaj liczbe nr %d \n",i+1);
     scanf("%d",&tab[i]);
    }
    
    tab=realloc(tab,(sizeof(int)*(n+2)));
    
    tab[n]=tab[0];   //t[n] - max
    tab[n+1]=tab[0]; //t[n+1] - min
    
    for (i=1;i<n;i++)
    {
    if (tab[i]>tab[n]) tab[n]=tab[i];
    if (tab[i]<tab[n+1]) tab[n+1]=tab[i];
    }
    printf("\n\n");
    for (i=0;i<n+2;i++) printf (" %d ",tab[i]);
    
  getch();
  return 0;
}

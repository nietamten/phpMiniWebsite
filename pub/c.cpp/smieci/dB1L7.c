
/*Opracowa� program, kt�ry utworzy dynamicznie tablic� liczb ca�kowitych o rozmiarze
n wczytywanym z klawiatury. Nast�pnie wczyta� z klawiatury n liczb. Rozszerzy� 
tablic� o 2 elementy. Policzy� warto�� maksymaln� i minimaln� i wpisa� je do rozszerzonej tablicy.
Wyprowadzi� zawarto�� tablicy w tym tak�e znalezione minimum i maksimum, 
na ekran. Przed zako�czeniem programu zwolni� pami�� przydzielon�.*/

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

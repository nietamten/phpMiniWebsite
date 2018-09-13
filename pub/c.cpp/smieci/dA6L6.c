
/*Napisz program, kt�ry korzysta z dw�ch tablic o rozmiarze 40- jedna to tablica
liczb ca�kowitych, druga to tablica wska�nik�w na liczby ca�kowite. Napisz 
funkcje, kt�ra ustala warto�ci losowe pierwszej tablicy (przedzia� [-3,10)), 
warto�ci drugiej ustawia na warto�ci adresy z pierwszej tablicy void 
ustaw(int a[],int *b[]);*/

#include <stdio.h>
#include <stdlib.h>


void ustaw(int a[],int *b[]);

int main(void)
{ 
    int x[40];
    int* y[40]; 

  ustaw(x,y);
  
    int i;
  
  printf("\nwartosci pierwszej tablicy:\n");
  for (i=0;i<40;i++) printf (" %d ",x[i]);  
  printf("\nwartosci wyluskane z adresow drogiej tablicy:\n");
  for (i=0;i<40;i++) printf (" %d ",*y[i]); 
  
  getch();	
  return 0;
}

void ustaw(int a[],int *b[])
{ 
     srand ( time(NULL) ); 
     int i;
     for (i=0;i<40;i++)
     {
          a[i]=(rand()%14)-3;
          b[i]=&a[i];
     }
}

/* Napisa� program kt�ry zci�gu n - liczb ca�kowitych podanych z klawiatury 
znajdzie �redni� warto�� u�ywaj�c p�tli do..while.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int a=0,n;
float x,s=0;
printf("\npodaj n ");
scanf ("%d",&n);
do{
a++;
printf("\n podaj %d liczbe ",a);
scanf ("%f",&x);
s=s+x;
}while (a<n);
printf ("srednia podanych liczb to %f ",s/n); 
getch();
  return 0;
}

/* Napisaæ program który zci±gu n - liczb ca³kowitych podanych z klawiatury 
znajdzie ¶redni± warto¶æ u¿ywaj±c pêtli do..while.
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

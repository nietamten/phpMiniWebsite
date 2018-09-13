/* Napisaæ program który w ci±gu n - liczb podanych z klawiatury znajdzie numer 
liczby najmniejszej
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int n,s=1,a;
 float x,y;
 printf ("podaj n ");
 scanf("%d",&n);
     printf ("podaj %d liczbe ",1); 
     scanf ("%f",&x); y=x;
 for (a=1;a<n;a++)
 { 
     printf ("podaj %d liczbe ",a+1); 
     scanf ("%f",&x);
     if (x<y) { s=a+1; y=x; };
 };
 
  printf ("najmniejsza liczba miala numer %d",s); 
getch();
  return 0;
}
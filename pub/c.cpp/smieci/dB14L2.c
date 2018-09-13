/* 
Napisaæ program obliczaj±cy n-ty wyraz ci±gu Fibonacciego 
(nie u¿ywaæ w³asnych funckji ani rekurencji.
*/


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n,a;

float x=0,y=1, p=0 ;

printf("Podaj n ");
scanf("%d",&n);

for (a=1;a<n;a++)
{
    p=y;
    y=y+x;
    x=p;
}

printf (" %d wyraz tego ciagu Fibonacciego to %f ",n,y);
getch();
  return 0;
}

/* Napisaæ funkcjê licz±c± n-ty wyraz ciagu Fibonnaciego (rekurencyjnie).
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fib (int p1, int p2 ,int x);

int main(void)
{
     int n;
 printf ("podaj n ");
 scanf("%d",&n);
  printf("%d wyraz ciagu fibonacciego to %d", n , fib(1,0,n));
  getch();	
  
}
int fib (int p1, int p2 ,int x)
{
if (x-1>0) 
return (fib ( p2,p1+p2,x-1));
else return p1+p2;  
}

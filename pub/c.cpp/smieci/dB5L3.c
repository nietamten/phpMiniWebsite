/* Napisac funkcjê int bc( unsigned int n ); zliczaj±cæ zapalone (czyli == 1) bity w n.
*/


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>




int bc(unsigned int n)
{
    int i=0,j;
 for(j=0;j<=31;j++)if ((n) & (1 << (j)))  i++;
 return i;
}
      
int main(void)
{ 
    
    unsigned int c;
printf("podaj kwote gredytu (k) \n");
scanf("%d",&c);
printf("\nilosc zapalonych bitow to: %d",bc(c));
getch();
}

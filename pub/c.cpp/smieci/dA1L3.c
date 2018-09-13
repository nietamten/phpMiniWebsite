/* Napisaæ funkcjê licz±c± silnie iteracyjnie.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(void)
{
     int n,s=1,i;
 printf ("podaj n ");
 scanf("%d",&n);
for (i=1;i<=n;i++) s*=i;
  printf("silnia z %d to %d", n ,s );
  getch();	
  
}

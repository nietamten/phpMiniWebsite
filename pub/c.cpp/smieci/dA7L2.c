/* Napisa� program licz�cy sum� od k do n (ci�g arytmetyczny) (k+ k+1+...+n) 
za pomoc� p�tli for.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int n,k,s=0,a;
 
 printf ("podaj k ");
 scanf("%d",&k);
 printf ("podaj n ");
 scanf("%d",&n);

  for (a=k;a<=n;a++) s+=a;
  printf ("suma to %d",s); 
getch();
  return 0;
}


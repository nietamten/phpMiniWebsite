/* Napisz funkcjê, który obliczy warto¶æ wyra¿enia 12+22+...+1002.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int f (void)
{
long int n=12,s=0;
while (n<=1002) {s+=n; n+=10;}
return s;
}


int main(void)
{
   
  printf("suma tego wyrazenia to %d",f() );
  getch();	
  
}
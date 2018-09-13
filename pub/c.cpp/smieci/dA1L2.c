/* Napisz program , który wczytuje z klawiatury 10 liczb zmiennoprzecinkowych 
i drukuje ilo¶æ liczb z przedzia³u -0.3...0.9.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int a=0,n;
float x;
for (n=1;n<=10;n++){
printf("\npodaj %d liczbe ",n);
scanf ("%f",&x);
if (x>=-0.3 && x<0.9) a++;
}
printf ("podano %d liczb z zakresu <-0.3 ; 0.9>",a); 
getch();
  return 0;
}

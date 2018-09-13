/*Okre¶liæ przez, które æwiartki uk³adu wspó³rzêdnych (lub o¶ X) przechodzi prosta postaci y=ax+b, gdzie a i b s± danymi wczytywanymi z klawiatury.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
float a,b,zero;
//dziendobry pobieramy liczby
printf("funkcja ma postac y=ax+b\n");
printf("podaj a i b\n");
scanf("%f%f/n",&a,&b);
//liczymy miejsce zerowe
zero=-(b/a);

// i ify

printf("Wykres funkcji przechodzi przez : ");

if (a>0)
{
 printf("cwirtke II cwiartke IV ");
 if (zero>0) printf(" cwiartke I ");
 if (zero==0) printf(" punkt [0,0] ") ;
 if (zero<0) printf(" cwiartke III ");
}

if (a==0)
{
if (b>0) printf(" cwiartke I cwiartke II ");
if (b==0) printf("  os OX ");
if (b<0) printf (" cwiartke III cwiartke IV ");
}

if (a<0)
{
 printf("cwirtke I cwiartke III ");
 if (zero>0) printf(" cwiartke II ");
 if (zero==0) printf(" punkt [0,0] ") ;
 if (zero<0) printf(" cwiartke IV ");
}

   getch();
   return 0;
}

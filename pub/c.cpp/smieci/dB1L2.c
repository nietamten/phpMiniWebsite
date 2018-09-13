/* Napisz program, który drukuj piramidkê postaci:
  *
 ***
*****
Piramidka mo¿e byæ tworzona z dowolnych znaków. G³êboko¶æ piramidki podaje 
u¿ytkownik
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n,a,b;
char z='x';
printf ("podaj n ");
scanf("%d",&n);
printf ("podaj jakis znak ");
scanf("%s",&z); //niewiedziec dlaczego nie moge wczytac znaku z %c 
 //nieprawidlowy wpis dzala dobrze
for (a=1;a<=n;a++)
{
    printf("\n");
    for (b=n-a;b>0;b--) printf(" "); 
    for (b=0;b<a;b++) printf("%c", z);
    for (b=1;b<a;b++) printf("%c", z);
}
getch();
  return 0;
}

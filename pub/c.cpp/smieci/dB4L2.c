/* 
Napisz program, kt�ry drukuj tr�jk�t postaci:
*
**
* *
*  *
**** 
Piramidka mo�e by� tworzona z dowolnych znak�w. G��boko�� piramidki podaje 
u�ytkownik .
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
for (a=0;a<=n;a++)
{
    printf("\n");
    
  for (b=1;b<=a;b++) if ((b==1)||(b==a)||(a==n))printf("%c", z); else printf(" ");

}
getch();
  return 0;
}

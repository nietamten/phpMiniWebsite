/* 
 Napisz program do obliczania najwi�kszego wsp�lnego dzielnika liczb a i b, 
 stosuj�c p�tl� o nieokre�lonej liczbie powt�rze� oraz najmniejsz� wsp�ln� 
 wielokrotno�� tych liczb
*/
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
float a , b, NWW , NWD, tmp , ab;
char s;
do{
printf ("Podaj a i b\n");
scanf("%f %f",&a,&b);

ab=a*b;
do{
 tmp=fmod(a,b); 
 a = b;                  //licze nww
 b = tmp;
} while(b!=0);

NWW=ab / a;

NWD=ab/NWW;

printf("\nNajwiekszy wspolny dzielnik podanych liczb to %f \n",NWD);

printf("\nCzy powtorzyc? (t/n)\n");
scanf("%s",&s);
}while (s=='t');
  return 0;
}

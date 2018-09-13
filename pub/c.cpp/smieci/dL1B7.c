/*#  Oblicz pole trójk±ta, gdy wspó³rzêdne wierzcho³ków (x1,y1), (x2,y2), (x3,y3) P = 0.5  |((x1 y2 - x2 y1)+(x2 y3 - x3 y2) + (x3 y1 - x1 y3))|.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
float x[3],y[3],P; 
int a;
printf("Program liczacy pole trojkata w ukladzie wspolzednych\n");

for (a=0;a<3;a++)
{
printf("podaj wartosc x%d\n",a+1);
scanf("%f",&x[a]);
printf("podaj wartosc y%d\n",a+1);
scanf("%f",&y[a]);
}

P=( (x[1]*y[2]-x[2]*y[1]) + (x[2]*y[3]-x[3]*y[2]) + (x[3]*y[1]-x[1]*y[3]) )/2;
if (P<0) P=-P;

printf("\n Pole tego trojkata to: %f",P);

   getch();
   return 0;
}

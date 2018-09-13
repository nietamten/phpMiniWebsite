/*Oblicz warto¶æ wyra¿eñ (a*c)/b (zwróæ uwagê, ¿e nie mo¿na dzieliæ przez zero) 
*/

#include <stdio.h>
#include <conio.h>

int main (void)
{
float a,b,c;
printf("Program obliczajacy a/(b+c)\n");
printf("Podaj kolejno wartosci a,b i c\n");
scanf("%f%f%f",&a,&b,&c);
if (b==0) {printf("zle dane"); getch(); return 1;}
printf("Wynik to:\n");
printf("%f\n",(a*c)/b);

   getch();
   return 0;
}

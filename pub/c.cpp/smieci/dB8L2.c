/* 
Napisz program przeliczj�cy temperatur� z celcjuszy na Fahrenheity w 
nieksonczonej p�tli. Program powininien si� zatrzyma�, gdy otrzyma dan� 
wej�ciow� o warto�ci mniejszej ni� -276 stopni, a dla warto�ci powy�ej 500 
stopni powinien drukowa� tekst "Zbyt duza wartosc".
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
float x=0;
while (x>-276){
printf ("\npodaj temperature w stopniach C ");
scanf("%f",&x);
if (x<500) printf("\nw stopniach fahrenheita jest to %f \n", ( (x*1.8)+32)  );
else printf ("\n za duza wartosc\n");
}
  return 0;
}

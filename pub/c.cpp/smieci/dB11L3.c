/*Dane s± liczby rzeczywiste x1, y1, x2, y2, x3, y3 bêd±ce wspó³rzêdnymi
 wierzcho³ków trójk±ta ABC. Napisz funckjê, która obliczy d³ugo¶ci jego
 ¶rodkowych (¶rodkow± trójk±ta nazywamy odcinek ³±cz±cy wierzcho³ek trójk±ta
 ze ¶rodkiem naprzeciwleg³ego boku trójk±ta).*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{ 
float xy[6][2];
int i;
printf("wszystkie wspolzedne musza byc dodatnie\n");
for (i=0;i<3;i++)
{
    printf("podaj x%d: ",i+1);
    scanf("%f",&xy[i][0]);
    printf("podaj y%d: ",i+1);
    scanf("%f",&xy[i][1]);
}

if (xy[0][0]>xy[1][0]) xy[3][0]=(xy[0][0]-xy[1][0])/2; else xy[3][0]=(xy[1][0]-xy[0][0])/2;
if (xy[0][1]>xy[1][1]) xy[3][1]=(xy[0][1]-xy[1][1])/2; else xy[3][1]=(xy[1][1]-xy[0][1])/2;
if (xy[0][0]>xy[2][0]) xy[4][0]=(xy[0][0]-xy[2][0])/2; else xy[4][0]=(xy[2][0]-xy[0][0])/2;
if (xy[0][1]>xy[2][1]) xy[4][1]=(xy[0][1]-xy[2][1])/2; else xy[4][1]=(xy[2][1]-xy[0][1])/2;
if (xy[1][0]>xy[2][0]) xy[5][0]=(xy[1][0]-xy[2][0])/2; else xy[5][0]=(xy[2][0]-xy[1][0])/2;
if (xy[1][1]>xy[2][1]) xy[5][1]=(xy[1][1]-xy[2][1])/2; else xy[5][1]=(xy[2][1]-xy[1][1])/2;

printf("\ndlugosc pierwszej srodkowej: %f",hypot(xy[0][0]-xy[5][0],xy[0][1]-xy[5][1]));
printf("\ndlugosc drogiej   srodkowej: %f",hypot(xy[1][0]-xy[4][0],xy[1][1]-xy[4][1]));
printf("\ndlugosc trzeciej  srodkowej: %f",hypot(xy[2][0]-xy[3][0],xy[2][1]-xy[3][1]));
getch();
}

/* 
Napisz program który znajdzie w podanym ci±gu liczb zawartych miêdzy 0 a 20 
najwiêksz± i najmniejsz± oraz poda, ile razy ka¿da z tych dwóch liczb wyst±pi³a.
Zak³adamy, ¿e ci±g o nieznanej z góry d³ugo¶ci bêdzie zakoñczony liczb± ujemn±.
W rozwi±zaniu nie wolno stsosowaæ tablic. Liczby powy¿ej 20 nale¿y pomin±æ.
*/
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
float a , b, x;
int la=1, lb=1;

//omijanie pierwszej liczby >20
do{
printf ("Podaj liczbe ");
scanf(" %f",&x);
if (x<0) break;
}while (x<20);

//zmienne ustawione tak zeby przy podaniu pierwszej liczby <0 wynik byl dobry
a=x;
b=x;

//ciag konczy liczba ujemna i zostaje tez uwzgledniona dlatego while zamiast do while
//chociaz z drogiej strony troche bez sesu robic licznik liczb najmniejszych skoro 
//wiadomo ze ostatnia bedzie najmniejsza
while (x>0){ 
printf ("Podaj liczbe ");
scanf(" %f",&x);

if (x<20){
if (x==a) la++;
if (x==b) lb++;
if (x>a) {a=x; la=1;}
if (x<b) {b=x; lb=1;} 
}

};

printf("\n Najwieksza z podanych liczb to %f, wystapila %d razy \n",a,la);
printf("\n Najmniejsza z podanych liczb to %f, wystapila %d razy \n",b,lb);

 getch();
 return 0;
  
}

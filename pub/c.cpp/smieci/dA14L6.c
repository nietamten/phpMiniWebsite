
/*Zdefiniowaæ sta³e (const) typu char, int, long, double. Zdefiniowaæ wska¼niki 
na sta³e. Wyprowadziæ adresy fizyczne sta³ych oraz ich zawarto¶ci (adres mo¿na 
otrzymaæ rzutuj±c wska¼nik na typ int i drukuj±c taka zmienn± na ekran, np. 
adres=(int)wsk.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
const char   a ;
const int    b ;
const long   c ;
const double d ;

char   *wa = &a;
int    *wb = &b;
long   *wc = &c;
double *wd = &d;

printf("Adres const char : %d\n",(int)wa);
printf("Adres const int : %d\n",(int)wb);
printf("Adres const long : %d\n",(int)wc);
printf("Adres const double : %d\n",(int)wd);
  getch();	
  return 0;
}

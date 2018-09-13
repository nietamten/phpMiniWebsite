
/*Opracowaæ funkcje umo¿liwiaj±ce zainicjowanie zmiennej strukturalnej typu CD
(typedef struct { char zespol[40]; char autor[20]; unsigned rok;}CD. Dane s± 
nastêpuj±ce prototypy:
a) CD w1(void) - wczytywanie z klawiatury, struktura zwracana przez return;
b) void w2(CD *x) - wczytywanie z klawiatury, struktura zwracana przez wska¼nik;
c) void losuj(CD *x) - wstawianie losowych danych do struktury wskazywanej przez 
s; do pól typu char[] wstawiany jest ³añcuch 'stra' zakoñczony losow± liczb± 
nale¿±c± do przedzia³u [1, 100), np. 'stra21', 'stra3', itd.; do pozosta³ych pól 
wstawiane s± losowe liczby (byle z sensem).
W programie g³ównym zainicjowaæ zmienn± typu CD za pomoc± ka¿dej z funkcji.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{
 char zespol[40];
 char autor[20];
 unsigned rok;
} CD;

CD w1(void)
{
 CD a;
 printf ("podaj zespol\n");
 scanf("%s",&a.zespol);
 printf ("podaj autora\n");
 scanf("%s",&a.autor);
 printf ("podaj rok\n");
 scanf("%d",&a.rok);
 return a;
}

void w2(CD *x)
{
 printf ("podaj zespol\n");
 scanf("%s",&x->zespol);
 printf ("podaj autora\n");
 scanf("%s",&x->autor);
 printf ("podaj rok\n");
 scanf("%d",&x->rok);
}

void losuj(CD *x)
{
     int i;
     char stra[20]="stra",q[3];

srand( (unsigned)time( NULL ) );
itoa(rand()%100,q,10);
strcat(stra,q);
strcpy(x->zespol,stra);
strcpy(stra,"stra");
itoa(rand()%100,q,10);
strcat(stra,q);
strcpy(x->autor,stra);
x->rok=1800+rand()%207;
}

void spr(CD x)
{
printf("\nzespol: %s \n",x.zespol);
printf("\nautor: %s \n",x.autor);
printf("\nrok: %d \n",x.rok);
getch();
}

int main(void)
{ 
  CD plyta;
  plyta=w1();
  spr(plyta);
  w2(&plyta);
  spr(plyta);
  losuj(&plyta);
  spr(plyta);
  return 0;
}

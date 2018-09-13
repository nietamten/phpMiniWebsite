/*Dany jest labirynt, jako dwuwymiarowa tablica (0- przestrzeñ wolna, -1 
- ¶ciana), punkt startowy (po³o¿enie w tablicy) oraz punkt koñcowy, oba punkty 
le¿± na obwodzie tablicy. Napisaæ funkcje znajduj±c± najkrótsz± drogê w 
labiryncie z miejsca docelowego do koñcowego. Informacja o najkrótszej drodze
ma byæ zwrócona w postaci jednowymiarowej tablicy zawieraj±cej wska¼niki do
poszczególnych etapów drogi (tzn. pierwszy element ma zawieraæ wska¼nik do
punktu startowego). Napisz funkcje sprawdzaj±c poprawno¶æ czê¶ciow± poprawno¶æ
rozwi±zania (czy to jest droga w tablicy). Do funkcji przekazuj wska¼niki na 
tablice z labiryntem i wska¼nik na tablice z wynikiem.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void szukaj (char *);
void menu(void);
void sonar (char *,char *);
char** znajdz(char *);
void pokaz (char *); 
void losuj(char *);
void sprawdz (char *,char *);
char** tworz(char *, char *);
int test(char **);

//funkcja glowna
int main(void)
{    
    char x='0';
    //TAB to tablica z labiryntem
    char TAB[12][12]={};
    //obsluga menu
   menu();	
   do{    
    if (x=='1') losuj(*TAB);
    if (x=='2') szukaj(*TAB);
    menu();
    x=getch();	
     }while(x != '3');

  return 0;
}

//wyswietla menu
void menu(void)
{
    system("CLS");
    printf("\n\n MENU:\n\n\n");
    printf("1. WYLOSUJ LABIRYNT\n\n");
    printf("2. ZNAJDZ DROGE\n\n");
    printf("3. ZAMKNIJ PROGRAM\n\n");
}

//wyswietla labirynt
void pokaz (char *T)
{
     int i;     
     printf("            ");
//indeksy pionowe
     for (i=0;i<10;i++) printf(" %d",i);
      printf("\n");
     for (i=0;i<144;i++)
      {
//indeksy poziome
          if ( i % 12 == 0 ) {
                              printf("\n\n        ");
                              if ((i/12>0)&&(i/12<11))
                               printf("%d ",i/12-1); 
                               else printf("  ");
                              }
         printf(" %c",T[i]);      
      }
}

//losuje labirynt
void losuj(char *T)
{
	  int i;
//wypelnia tablice jedynkami     
     for (i=0;i<144;i++) (char)*(T+i)='1';     
//inicjuje randoma
	  srand ( time(NULL) );

     do{
     for (i=0;i<144;i++) 
      if ( (i%12 != 0 ) && (i>12) && (i<132) && ((i+1)%12 != 0 ))
//gdy jest za duzo mozliwosci algorytm szukania nie daje rady (dziala za wolno)
//dlatego %2 a nie %3 co by zrobilo przeciag w labiryncie
      if (rand() % 2 ==0 )
       (char)*(T+i)='1';
        else (char)*(T+i)='0';

     system("CLS");
     printf("OTO WYLOSOWANY LABIRYNT:\n\n\n\n");
     pokaz(T);
     printf("\n\n\nPODOBA SIE? JAK TAK TO 0\n");
     i=getch();
	 }while(i != '0');
}

//kopiuje tablice z labiryntem, wywoluje funkcje znajdujaca najkrutsza droge
//ktora zwraca tablice wskaznikow na kopie labiryntu, sprawdza funkcja "test"
//czy znalezion droga jest prawidlowa, wpisuje droge do kopii tablicy
//(tam gdzie wskazuja wskazniki) i wyswietla jako wynik 

void szukaj (char *T)
{
//tworze tablice pomocnicza
     int i;
     char Y[144],**Q;

//kopiuje labirynt do pomocniczej
for (i=0;i<144;i++)
(char)*(Y+i)=(char)*(T+i);

     system("CLS");     
//do Q pobiera wskaznik na tablice wskaznikow na droge w tablicy pomocniczej Y
     Q=znajdz(Y);
//jezeli Q wskazuje na prawidlowa droge 
     if (test(Q)==0){
//ta wpisuje w miejsca wskazywane przez tablice wskaznikow identyczne wartosci
//zby droga byla widoczna na tablicy pomocniczej i wyswietlam ja jako wynik
                   i=0;
                   while( (char*)*(Q+i) != NULL)
                   {(char)*Q[i]=2;i++;}
     printf("\nDROGA PRZESZLA TEST\n\nOTO ONA:\n\n");
     pokaz(Y);}else printf("\n\nBLAD! DROGA NIE PRZESZLA TESTU");
//zwalniam pamiec tablicy wskaznikow
free(Q);
getch();
}

//sprawdza czy otrzymana tablica wskaznikow jest droga w labiryncie
int test(char **X)
{
    int i=0,x=0;
    if(X!=NULL)
               while(X[i]!=NULL)
               {
//printf("\n%c",*X[i]);getch();
                if( (*X[i]!='P') && (*X[i]!='K') && (*X[i]!='0')) x=1;
                i++;
               }else x=1;
return x;
}

//bobiera wspolzedne poczatku i konca drogi wpisuje do swojej kopii labiryntu
//i uruchamia wlasciwa funkcje szukajonca(sonar), zwraca wartosc zwracana
//przez sonar
char** znajdz(char *A)
{ 
//pobiera wspolzedne
char x;
int w[4],i,j;

   do{  
     system("CLS");
     pokaz(A);
     printf("\n\nPODAJ WSPOLZEDNE POCZATKU\nNUMER KOMUMNY A NASTEPNIE WIERSZA");
     x=getch();
     w[0]=atoi(&x);
     x=getch();
     w[1]=atoi(&x);
     printf("\nPODAJ WSPOLZEDNE KONCA\nNUMER KOMUMNY A NASTEPNIE WIERSZA");
     x=getch();
     w[2]=atoi(&x);
     x=getch();
     w[3]=atoi(&x);

//sprawdza wspolzedne
     i=0;
//czy wspolzedne leza na krawedzi
     if ( (w[0]!=0 && w[0]!=9) && (w[1]!=0 && w[1]!=9) ) i=1;
     if ( (w[2]!=0 && w[2]!=9) && (w[3]!=0 && w[3]!=9) ) i=1;
//czy nie wprowadzono liter zamiast cyfr (bo cyfry wiekszej od 9 nie ma)
     for (j=0;j<4;j++)     
     if (w[j]>9||w[j]<0) i=1;
//czy sie nie pokrywaja
      if ( w[0]==w[2] && w[1]==w[3])i=1;
//jezeli blad pobiera ponownie
     if(i==1) printf("\nBLEDNE DANE!! PUNKTY MUSZA LEZEC NA KRAWEDZI"); 
     else printf("\nWSPOLZEDNE OK");
     getch();
     }while(i==1);

//zeby podane wspolzedne pasowaly do tablicy
for(i=0;i<4;i++) w[i]+=1;

//czysci ekran
     system("CLS");

//wynikowa tablica pomocnicza
char X[144];

//wypelniam tablice wynikowa identycznymi znakami
     for (i=0;i<12;i++)
      for (j=0;j<12;j++) (char)*(X+(i*12+j))=1;

//wpisuje punkty poczatku i konca
(char)*(A+w[1]*12+w[0])='P';
(char)*(A+w[3]*12+w[2])='K';

//wyswietla utworzona tablice z zaznaczonymi punktami o podanych wspolzednych
printf("LABIRYNT Z ONACZONYMI WYBRANYMI PUNKTAMI:\n\n");
pokaz(A);
printf("\n\nKLIKNIJ ABY WYSZUKAC DROGE");
getch();
     system("CLS");

//wyszukuje najkrotsza
//A to labirynt, X to kopia labiryntu z oznaczona droga
		sonar(A,X);
        char **p;
//do p wpisywany jest wskaznik na tablice wskaznikow wygenerowany z tablicy
//labiryntu i pomocniczej tablicy wynikow
        p=tworz(A,X);
      return p;
}

//wpisuje do tablicy wskaznikow adresy kolejnych etapow drogi z pomocniczj kopii labbiryntu 
//na podstawie tablicy ze znaleziona droga i wskaznika na kopie tablicy z labiryntem
//tablica z labiryntem jest potrzebna aby znac poczatek oraz adresy w pamieci
//na ktore ma wskazywac tablica wynikowa wskaznikow
//zwraca wskaznik na tablice wskaznikow zgodnie z poleceniem
char** tworz(char *A, char *B)
//A - labirynt B - droga
{
system("CLS");
printf("ZAPISUJE ZNALEZIONA DROGE DO TABLICY WSKAZNIKOW");

       char **X,*q;
       int i,j,d=0,x,y=0;

//licze jaka dluga jest droga zeby wiedziec jaka duza ma byc tablica
for (i=0;i<144;i++) if ((char)*(B+i) == 1)d++;

//jezeli nie znaleziono drogi
if (d>100)  return NULL;

//alokuje pamiec dla tablicy
X = malloc( sizeof(char*)*(d+1) );

//znajduje poczatek i wpisuje w tablice adres
for (i=0;i<12;i++)
for (j=0;j<12;j++)
 if ((char)*(A+(i*12)+j) == 'P'){y=i;x=j; 
  (char)*(B+(y*12)+x)=2;} 

//wpisuje don adres pierwszego elementu
X[0]=(char*)(A+(y*12)+x);
X[d]=NULL;
i=1;

do{
/* debuger :)
    pokaz(B);
    printf("\nnr %d",i);
    printf("\nlewo %c ",(char)*(B+(y*12)+x-1));
    printf("\nprawo %c ",(char)*(B+(y*12)+x+1));
    printf("\ngora %c ",(char)*(B+((y-1)*12)+x));
    printf("\ndol %c ",(char)*(B+((y+1)*12)+x)); getch();
*/
  if ( (char)*(B+(y*12)+x+1) == 1){
                         (char)*(B+(y*12)+x)=2;
                          x++;
                          X[i]=(char*)(A+(y*12)+x);
                         i++;
                         }
  if ((char)*(B+(y*12)+x-1) == 1){
                          (char)*(B+(y*12)+x)=2;
                          x--;
                          X[i]=(char*)(A+(y*12)+x);
                          i++;
                         }
  if ((char)*(B+((y+1)*12)+x) == 1){
                          (char)*(B+(y*12)+x)=2;
                          y++;
                          X[i]=(char*)(A+(y*12)+x);
                          i++;
                         }
  if ((char)*(B+((y-1)*12)+x) == 1){
                            (char)*(B+(y*12)+x)=2;
                          y--;
                          X[i]=(char*)(A+(y*12)+x);
                          i++;
                         }
 }while((char)*(A+(y*12)+x)!='K');
(char)*(B+(y*12)+x)=2;
return X;
}

//funkcja sprawdza wszystkie mozliwe drogi i jezeli "zniknie" znak konca
//labiryntu(tzn bedzie zastopiony znakiem drogi) to sprawdza czy znaleziona
//droga jest ktorsza od zapisanej. poczatkowa znaleziona tablica z droga
//jest pelna "znakow drogi" przez co zawsze bedzie dluzsza od znalezionej
//a jezeli zadna droga nie zostanie znaleziona to latwo bedzie stwierdzic
//to po tablicy wynikowej
//calosc jest niesamowicie powolna ale nie moglem wymyslic nic lepszego
void sonar (char *C,char *W)
//C - labirynt
//W - tablica z wynikiem
{ 

int i,j,x=0,y=0;
char T[144];

for(i=0;i<144;i++) (char)*(T+i)=(char)*(C+i);

//sprawdzam czy jest koniec 
  x=0;
  for (i=0;i<144;i++)
    if ( (char)*(T+i) == 'K') x=1;

//jezeli jest
if (x==1)
{
//szukam poczatku i zapamietuje wspolzedne
//w miejsce poczatku wpisuje 1
  for (i=0;i<12;i++)
   for (j=0;j<12;j++)
    if ( (char)*(T+(i*12+j)) == 'P') {x=i; y=j;}
//poczatek zamienia na droge
  (char)*(T+(x*12+y))=1;

/*
system("CLS");
printf("SZUKAM...\n\n");
pokaz(T);
*/
 
//jezeli w polu obok poczatku jest 0 lub K to zamieniam na poczatek i odpala sonar
//funkcja uruchamia sie rekurencyjnie dla kazdego sasiedniego pola zawieracajeco
//0 lub koniec
//w prawo
  if ((char)*(T+((x+1)*12+y))=='0' || (char)*(T+((x+1)*12+y))=='K'){
                      (char)*(T+((x+1)*12+y))='P';
                      sonar(T,W);
                      (char)*(T+((x+1)*12+y))='0';
                      }
//w gore
  if ((char)*(T+(x*12+y+1))=='0'||(char)*(T+(x*12+y+1))=='K'){
                      (char)*(T+(x*12+y+1))='P';
                      sonar(T,W);
                      (char)*(T+(x*12+y+1))='0';
                      }                      
//w lewo                      
  if ((char)*(T+((x-1)*12+y))=='0'||(char)*(T+((x-1)*12+y))=='K'){
                      (char)*(T+((x-1)*12+y))='P';
                      sonar(T,W);
                      (char)*(T+((x-1)*12+y))='0';
                      }
//w dol
  if ((char)*(T+(x*12+y-1))=='0'||(char)*(T+(x*12+y-1))=='K'){
                      (char)*(T+(x*12+y-1))='P';
                      sonar(T,W);
                      (char)*(T+(x*12+y-1))='0';
                      }
}else sprawdz(T,W);
}

//liczy ilosc znakow drogi w znalezionej tablicy oraz w tablicy
//z wczesniej zapisana droga, jezeli ta pierwsza jest ktorsza
//to wpisuje ja do znlezionej       
void sprawdz (char *A,char *W)
{
      int x=0,y=0,i,j;

//sprawdzam czy sa poczatki jak tak to zmieniam je na droge
//licze dlugosc znalezionej drogi
  for (i=0;i<144;i++)
{
   if ((char)*(A+i) == 'P') (char)*(A+i) = 1;
    if ((char)*(A+i) == 1) x++;
}
//licze dlugosc zapisanej drogi
  for (i=0;i<144;i++)
    if ((char)*(W+i) == 1) y++;

//jezeli znaleziona droga jest krotsza od zapisanej
//to wpisuje do znalezionej
if(y>x)
  for (i=0;i<12*12;i++)
    (char)*(W+i)=(char)*(A+i);
} 




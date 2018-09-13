Plik zad1.pas:
program zad1;

var
a:byte;
b:text;

begin
assign(b,'plik.txt');
rewrite(b);
writeln ('podaj liczbe z zakresu 0-255');
readln(a);
write(b,a);
close(b);
a:=0;
reset(b);
read(b,a);
close(b);
writeln(a);
readln;
end.Plik zad2.pas:
program zad2;
var
A:array[1..10] of integer;
b:byte;
c:text;
begin
writeln('pdaj 10 liczb');
for b:=1 to 10 do
readln(A[b]);

assign(c,'plik.txt');
rewrite(c);
for b:=1 to 10 do
begin
writeln(c,A[b]);
writeln(c,'*');
end;
close(c);
end.Plik zad3.pas:
program zad3;
var
a,b:integer;
c:text;
d:string;
begin
writeln('pdaj nazwe pliku');

readln(d);

assign(c,d);
reset(c);
readln(c,d);
close(c);
b:=0;
for a:=1 to length(d) do
if d[a]='A' then inc(b);
writeln('w pierwszym wierszu podanego pliku jest ',b,' liter A');
readln;
end.Plik zad4.pas:
program zad4;
 
{$APPTYPE CONSOLE}

uses
  SysUtils;

type
piwo=record
nazwa:string;
producent:string;
vol:byte;
pojemnosc:integer;
cena:real;
end;

procedure zapisz (A:piwo;plik:string);
var
Q:file of piwo;
begin
assign(Q,plik);
rewrite(Q);
write(Q,A);
close(Q);
writeln('zapisano');
readln;
end;

procedure odczytaj (var A:piwo;plik:string);
var
Q:file of piwo;
begin
assign(Q,plik);
reset(Q);
read(Q,A);
close(Q);
writeln('dane zostaly odczytane z pliku');
readln;
end;

procedure pobierz (var A:piwo);
begin
writeln('podaj nazwe piwa');
readln(A.nazwa);
writeln('podaj producenta piwa');
readln(A.producent);
writeln('podaj moc piwa w %');
readln(A.vol);
writeln('podaj pojemnosc opakowania w mililitrach');
readln(A.pojemnosc);
writeln('podaj cene w PLN');
readln(A.cena);
writeln('dane zostaly pobrane jako tymczasowe zostana zachowane do zakonczenia programu');
readln;
end;

procedure wyswietl (A:piwo);
begin
writeln;
writeln('Aktualnie przechowywane dane:');
writeln;
writeln('Nazwa: ',A.nazwa);
writeln('Producent: ',A.producent);
writeln('Moc: ',A.vol,'%');
writeln('Pojemnosc opakowania: ',A.pojemnosc,' mililitrow');
writeln('Cena: ',A.cena:4:2,' PLN');
readln;
end;

var
X:file of piwo;
nazwa:string;
Y:piwo;
wybor:byte;

begin
writeln('podaj nazwe pliku ktorego chcesz uzywac (jego zawartosc zostanie usunieta)');
readln(nazwa);


{assign(X,nazwa);
rewrite(X);
close(X);}


repeat
writeln('Co chcesz zrobic?');
writeln;
writeln('1. Pobierz dane z klawiatury do pamieci tymczasowej');
writeln('2. Wyswietl dane przechowywane w pamieci tymczasowej');
writeln('3. Zapisz dane z pamieci tymczasowej do pliku');
writeln('4. Odczytaj z pliku do pamieci tymczasowej');
writeln('5. Zakoncz program');
writeln;
writeln('Twoj wybor: ');
readln(wybor);
case wybor of
1: pobierz (Y);
2: wyswietl(Y);
3: zapisz (Y,nazwa);
4: odczytaj (Y,nazwa);
5: writeln('---');
else writeln('zly wybor');
end;
until wybor=5;

end.
  { TODO -oUser -cConsole Main : Insert code here }

Plik zad5.pas:
program zad5;


var
nazwa1,nazwa2,temp:string;
A,B:text;
X:array[1..100] of integer;
i,y,z,q:integer;

begin
writeln('podaj nazwe pliku do odczytu');  {inicjowanie plikow}
readln(nazwa1);
writeln('podaj nazwe pliku do zapisu');
readln(nazwa2);
assign(A,nazwa1);
assign(B,nazwa2);
reset(A);

i:=0;  {odczyt z pliku}
while not eof(A) do
begin
inc(i);
readln(A,X[i]);
readln(A,temp);
end;
close(A);

for q:=1 to 100 do  {sortowanie}
for y:=1 to 99 do if X[y]<X[y+1] then
begin
z:=X[y];
X[y]:=X[y+1];
X[y+1]:=z;
end;

rewrite(B);  {zapis do pliku}
for y:=1 to i do
begin
writeln(B,X[y]);
writeln(B,'*');
end;
close(B);
end.
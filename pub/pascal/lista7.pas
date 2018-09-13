Plik zad1.pas:
program zad1;
var
a:integer;
b:char;
begin
repeat
writeln ('podaj liczbe do konwersji');
repeat
readln(a);
until a>0;
writeln;
repeat
write(a mod 2 :3);
a:=a div 2;
until a=0;
writeln;
writeln ('czy zakonczyc?t/n');
readln(b);
until b='t';
end.Plik zad2.pas:
program zad2;
var
a:integer;
b:char;
c:string;

begin

repeat
writeln('podaj liczbe do konwersji');
repeat
readln(a);
until a>0;
writeln;

repeat

if a mod 16<10 then write(a mod 16 :3) 
else  write (chr(55+(a mod 16)) :3);

a:=a div 16;
until a=0;




writeln;
writeln ('czy zakonczyc?t/n');
readln(b);
until b='t';
end.Plik zad3.pas:
program zad3;
var
a:array[1..100] of integer;
b:char;
c:byte;
d,e:integer;
begin
repeat
writeln('podaj 10 liczb z zakresu <-10,10)');
for c:=1 to 10 do 

repeat
writeln('podaj ',c,' element tablicy');
readln(a[c]);
until ((a[c]>=(-10)) and (a[c]<10));
d:=0;
e:=0;
for c:=1 to 10 do 
if (a[c] mod 2) = 1 then d:=d+a[c]
else e:=e+a[c];
writeln('wprowadzona tablica tablica to:');
writeln;
for c:=1 to 10 do 
write (a[c]:3);
writeln;
writeln('suma niepazystych elementow tablicy to ',d);
writeln('suma pazystych elementow tablicy to ',e);
writeln;
writeln ('czy zakonczyc?t/n');
readln(b);
until b='t';
end.Plik zad4.pas:
program zad4;
var
A:array[1..5,1..5] of byte;
b:char;
c,d,e:byte;
begin
randomize;
repeat
for c:=1 to 5 do
begin
for d:=1 to 5 do 
begin
A[c][d]:=random(11)+10;
write(A[c][d]:3);
end;
writeln;
end;
d:=0;
for c:=1 to 5 do
d:=d+a[1][c];
writeln('suma elementow pierwszego wiersza to ',d);

writeln('podaj numer kolumny 1-5');
repeat
readln(c);
until ((c>0) and (c<6));
d:=A[1][c];
for e:=1 to 5 do
if d>A[e][c] then d:=A[e][c];
writeln('najmniejszy element  ',c,' kolumny to ',d);

writeln;
writeln ('czy zakonczyc?t/n');
readln(b);
until b='t';
end.Plik zad5.pas:
program zad5;

var
A:array[1..10,1..10] of integer;
b:char;
c,d,e:byte;
x:integer;
begin
randomize;
writeln('podaj rozmiar tablicy 3-10');
repeat
readln(c);
until ((c>2)and(c<11));
repeat
for d:=1 to c do
begin
for e:=1 to c do 
begin
A[d][e]:=random(21)-10;
write(A[d][e]:4);
end;
writeln;
end;
x:=0;
for d:=1 to c do
for e:=1 to c do 
if ((d mod 2 = 0) and (e mod 2 = 0)) then x:=x+A[d][e];
writeln('sume elementow o pazystych wspolzednych to ',x);
writeln;
writeln ('czy zakonczyc?t/n');
readln(b);
until b='t';
end.
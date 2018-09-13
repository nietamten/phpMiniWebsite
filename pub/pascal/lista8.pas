Plik zad1.pas:
program zad1;
var
a:integer;
b:byte;
y:real;

function ciag (n:byte):real;
var
a:byte;
suma,b:real;

begin
suma:=0;
b:=0;
for a:=1 to n do
if a mod 2 = 0 then
begin
b:=(a-1)-(1/a);
suma:=suma+b;
write(b:8:3);
end;
ciag:=suma;

end;


begin
writeln ('podaj pazyste n 1-255');
repeat
readln(b);
until ((b>1)and(b<255)and (b mod 2 = 0));
y:=0;
y:=ciag(b);
writeln;
writeln ('suma ciagu dla n=',b,' to ',y:5:3);


readln;
end.Plik zad2.pas:
program zad2;
type
tablica=array[1..10] of array[1..10] of integer;
var 
A,Z:tablica;
x,y:byte;


function spr (B:tablica;var C:tablica):boolean;
var
x,y:byte;
begin
for x:=1 to 10 do
for y:=1 to 10 do
if ((B[x][y] mod 2) = 0) then C[x][y]:=1 else C[x][y]:=0;
end;

begin                     {program sprawdza dzialanie napisanej funkcji}
randomize;
for x:=1 to 10 do
for y:=1 to 10 do
A[x][y]:=random(20);

for x:=1 to 10 do begin
for y:=1 to 10 do
write(A[x][y]:5);
writeln;
end;
spr(A,Z);
writeln;
for x:=1 to 10 do begin
for y:=1 to 10 do
write(Z[x][y]:5);
writeln;
end;
readln;
end. Plik zad3.pas:
program zad3;
type
tablica1 = array[1..10,1..10] of integer;
tablica2 = array[1..6] of integer;

var
A:tablica1;
B:tablica2;
c,d:byte;

function maxmin (X:tablica1;var Y:tablica2):boolean;
var
a:integer;
b,c:byte;
begin

a:=X[1][1]; {max}
for b:=1 to 10 do
for c:=1 to 10 do 
if a>X[b][c] then a:=X[b][c];
Y[1]:=a;

a:=X[1][1]; {min}
for b:=1 to 10 do
for c:=1 to 10 do 
if a<X[b][c] then a:=X[b][c]; 
Y[4]:=a;

a:=X[1][1]; {1 max}
for b:=1 to 10 do
if a<X[1][b] then a:=X[1][b]; 
Y[2]:=a;

a:=X[1][1]; {2 max}
for b:=1 to 10 do
if a<X[2][b] then a:=X[2][b]; 
Y[3]:=a;

a:=X[1][1]; {1 min}
for b:=1 to 10 do
if a>X[1][b] then a:=X[1][b]; 
Y[5]:=a;

a:=X[1][1]; {2 min}
for b:=1 to 10 do
if a>X[2][b] then a:=X[2][b]; 
Y[6]:=a;
end;


begin        {program sprawdza dzialanie funkcji}
randomize;

for c:=1 to 10 do
for d:=1 to 10 do 
A[c][d]:=random(100);

for c:=1 to 10 do begin
for d:=1 to 10 do 
write(A[c][d]:5);
writeln;
end;

maxmin(A,B);

writeln;

for c:=1 to 6 do
write(B[c]:5);

readln;
end.Plik zad4.pas:
program zad4;

type
tablica= array[1..10,1..10] of integer;

var
X:tablica;

procedure losowanie (var A:tablica);
var
b,c:byte;
begin
randomize;
for b:=1 to 10 do
for c:=1 to 10 do
A[b][c]:=random(21)-10;

for b:=1 to 10 do begin
for c:=1 to 10 do
write (A[b][c]:3);
writeln;
end;
end;

begin
losowanie(X);
readln;
end.Plik zad5.pas:
program zad5;


type
tablica= array[1..10,1..10] of integer;

var
X,Y:tablica;
b,c:byte;

procedure kwadrat (tab1:tablica; var tab2:tablica);
var
b,c:byte;
begin
for b:=1 to 10 do
for c:=1 to 10 do
tab2[b][c]:=tab1[b][c]*tab1[b][c];

end;





begin		{sprawdza procedure}

randomize;
for b:=1 to 10 do
for c:=1 to 10 do
X[b][c]:=random(21);

kwadrat(X,Y);

for b:=1 to 10 do begin
for c:=1 to 10 do
write (X[b][c]:3);
writeln;
end;

writeln;

for b:=1 to 10 do begin
for c:=1 to 10 do
write (Y[b][c]:5);
writeln;
end;

readln;
end.Plik zad6.pas:
program zad5;


type
tablica= array[1..10,1..10] of integer;

var
X:tablica;
b,c:byte;

procedure zero (tab:tablica);
var
b,c,d,e:byte;
begin
d:=0;
e:=0;
for b:=1 to 10 do
for c:=1 to 10 do
begin
if tab[b][c]>0 then inc(d);
if tab[b][c]<0 then inc(e);
end;

for b:=1 to 10 do begin
for c:=1 to 10 do
write (tab[b][c]:3);
writeln;
end;
writeln('ilosc elementow wiekszych od 0: ',e);
writeln('ilosc elementow mniejszych od 0: ',d);
end;





begin		{sprawdza procedure}

randomize;
for b:=1 to 10 do
for c:=1 to 10 do
X[b][c]:=random(21)-10;

zero(X);



readln;
end.
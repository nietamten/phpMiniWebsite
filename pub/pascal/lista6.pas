Plik ZAD1.PAS:
program zad1;
var
 A : array[1..5,1..5] of byte;
b,c,suma:integer;

begin
writeln('podaj 25 liczb kazda z zakresu (5,10)');
for b:=1 to 5 do
for c:=1 to 5 do begin
writeln('podaj liczbe umieszczona w tablicy na mejscu ',b,' ',c);
repeat
readln(A[b][c]); 
until ((A[b][c]>5) and (A[b][c]<10));
end;
writeln;
writeln('podane przez ciebie liczby to:');
for b:=1 to 5 do begin
for c:=1 to 5 do 
write(A[b][c]:3);
writeln;
end;
suma:=0;
for b:=1 to 5 do 
for c:=1 to 5 do
suma:=suma+A[b][c];
writeln('suma wszystkich podanych liczb to ',suma);
readln;
end.Plik ZAD2.PAS:
program zad2;
var
A: array [1..5,1..5] of integer;
b,c:byte;
suma:integer;
begin
randomize;
for b:=1 to 5 do 
for c:=1 to 5 do
A[b][c]:=random(201)-100;
writeln('wylosowano tablice');
for b:=1 to 5 do begin 
for c:=1 to 5 do
write(A[b][c]:3);
writeln;
end;
suma:=0;
for b:=1 to 5 do  
suma:=suma+A[b][1];
for b:=1 to 5 do  
suma:=suma+A[b][5];
writeln('suma liczb z pierwszej i ostatniej kolumny to ',suma);
readln;
end.Plik ZAD3.PAS:
program zad3;
var
A: array [1..5,1..5] of integer;
b,c:byte;
suma:integer;
x:char;
begin
repeat
randomize;

for b:=1 to 5 do 
for c:=1 to 5 do
A[b][c]:=random(11);
writeln('wylosowano tablice');

for b:=1 to 5 do begin 
for c:=1 to 5 do
write(A[b][c]:3);
writeln;
end;

suma:=0;
for b:=1 to 5 do 
for c:=1 to 5 do
if A[b][c] mod 2 = 0 then suma:=suma+A[b][c];
writeln('suma pazystych elementow tablicy to ',suma);
writeln('czy wykonac jeszcze raz t/n');
readln(x);
until x='n';
end.Plik ZAD4.PAS:
program zad4;

var
A: array [1..5,1..5] of byte;
b,c:byte;
x:char;

begin
repeat

for b:=1 to 5 do 
for c:=1 to 5 do
A[b][c]:=0;
for b:=1 to 5 do 
for c:=1 to 5 do
if ((b=c) or (b+c=6)) then A[b][c]:=1;
for b:=1 to 5 do begin 
for c:=1 to 5 do
write(A[b][c]:3);
writeln;
end;
writeln('czy wykonac jeszcze raz t/n');
readln(x);
until x='n';
end.Plik ZAD5.PAS:
program zad5;
var
A: array [1..10,1..10] of byte;
b,c:byte;

begin
for b:=1 to 10 do 
for c:=1 to 10 do
if ((b+c) mod 2) = 0 then A[b][c]:=0 else A[b][c]:=1;

for b:=1 to 10 do begin 
for c:=1 to 10 do
write(A[b][c]:3);
writeln;
end;

readln;
end.
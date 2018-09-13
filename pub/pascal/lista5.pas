Plik zad1.pas:
program zad1;


var
a:integer;
b:char;
begin

  repeat
  writeln('podaj jakas liczbe');
  readln(a);
  writeln('podana liczba ma ', a mod 10 ,' jednosci');
  writeln('czy powtorzyc? t/n');
  readln(b);
  until b='n';
  end.
Plik zad2.pas:
program zad2;




var
a,c,b,d:integer;

begin
 
writeln('podaj 2 liczby');
readln(a);
readln(b);
d:=1;
for c:=1 to a do
if ((a mod c=0) and (b mod c=0)) then
if c>d then d:=c;
writeln('najwiekszy wposlny dzielnik podanych liczb to ',d);
readln; 

end.
 Plik zad3.pas:
program zad3;




var
a,b,c,d:integer;
x:char;

begin
 repeat
writeln('podaj kolejno 10 liczb');
b:=0;
c:=0;
for d:=1 to 10 do
begin
readln(a);
if a mod 2 = 1 then c:=c+1 else b:=b+1;
end;
writeln('ilospc podanych liczb niepazystych: ',c);
writeln('ilospc podanych liczb pazystych: ',b);
writeln('czy powtorzyc? t/n');
  readln(x);
  until x='n';

end.
 Plik zad4.pas:
program zad4;





var
 A:array[1..100] of integer;
 c,b,d,e:integer;
 x:char;
 begin
 repeat
 d:=0;
 e:=0;
  Randomize;
 for c:=1 to 100 do
 begin
 repeat
 b:=random(11)-5;
 until not
 (b=0);
 a[c]:=b;
 write(a[c],' ');
 end;
 for c:=1 to 100 do
 begin
 if a[c]=5 then d:=d+1;
 if a[c]=-5 then e:=e+1;
 end;
  writeln;
  writeln ('wylosowanych piatek bylo ', d);
  writeln ('wylosowanych minus piatek bylo ', e);
  writeln('czy powtorzyc t/n');
  readln(x);
  until x='n';

end.
Plik zad5.pas:
program zad5;




 var
a:array[1..10] of char;
x:char;
  b:integer;
begin

repeat
  writeln('podaj 10 znakow');
  for b:=1 to 10 do readln(a[b]);
  writeln;
  for b:=1 to 10 do write(' ', a[b]);
writeln('czy powtorzyc? t/n');
  readln(x);
  until x='n';
  end.
 Plik zad6.pas:
program zad6;




var
 a:array[1..5] of integer;
 b,min,max:integer;
 x:char;
 begin
 repeat
 writeln('podaj 5 liczb');
for b:=1 to 5 do
repeat
 readln(a[b]);
until ((a[b]>-100) and (a[b]<100));
 min:=a[1];
max:=a[1];
for b:=1 to 5 do
begin
if min<a[b] then min:=a[b];
if max>a[b] then max:=a[b];
end;
writeln('najmniejsza z podanych liczb to ', max,' a najwieksza to ', min);
writeln('czy powtorzyc? t/n');
readln(x);
until x='n';

end.
 
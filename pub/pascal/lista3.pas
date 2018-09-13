Plik zad1.pas:
program zad_1;

var
a,b,c,d:integer;
x:char;
begin

repeat
b:=0;
c:=0;
writeln('podaj 5 liczb potwierdzajac enter');
for d:=1 to 5 do
begin
readln(a);
if a>0 then b:=b+1;
if a<0 then c:=c+1;
end;
writeln('ilosc podanych liczb dodatnich: ',b);
writeln('ilosc podanych liczb ujemnych: ',c);
writeln('czy powtorzyc? (t/n)');
readln(x);
until x='n' 
end.Plik zad2.pas:
program zad_2;

var
a,b,c:integer;
x:char;
begin

repeat
b:=1;
writeln ('podaj jakas liczbe');
readln (a);
for c:=1 to a do
b:=b*c;
writeln('silnia z podanej liczby wynosi ',b);
writeln('powtorzyc?(t/n)');
readln(x);
until x='n' 
end.Plik zad3.pas:
program zad_3;

var
a,b,c:integer;
x:char;
begin
repeat
writeln('podaj 5 liczb');
readln(a);
for c:=1 to 4 do 
begin
readln(b);
if a>b then a:=b;
end;
writeln('najmniejsza podana liczba to ',a);
writeln('czy powtorzyc?(t/n)');
readln(x);
until x='n' 
end.Plik zad4.pas:
program zad_4;

var
a,b:string;
c:integer;
x:char;
begin
repeat
writeln('podaj 5 ciagow znakow');
readln(a);
for c:=1 to 4 do 
begin
readln(b);
if length(a)<length(b) then a:=b;
end;
writeln('najdluzszy ciag znakow to ',a);
writeln('czy powtorzyc?(t/n)');
readln(x);
until x='n' 
end.Plik zad5.pas:
program zad_5;

var
a,b:integer;
x:char;
begin
repeat
writeln('podaj 2 wartosci z ktorych dorga bedzie wieksza od pierwszej conajmniej o 3');
readln(a);
readln(b);
a:=a+1;
b:=b-1;
writeln(' a - wyswietl wszystkie liczby pomiedzy wprowadzonymi wartosciami');
writeln(' b - wyswietl tylko liczby dodatnie ');
readln(x);
writeln('-------');
case x of
'a': for a:=a to b do writeln (a);
'b': for a:=a to b do if  not a<0 then writeln(a);
else writeln('zly wybor')
end;
writeln('-------');
writeln('czy powtorzyc?(t/n)');
readln(x);
until x='n' 
end.
Plik ZAD1.PAS:
program zad1;
var
a,b,c:integer;
begin
writeln('podaj 2 liczby');
readln(a);
readln(b);
if a+b>50 then
begin
writeln('podaj jeszcze jedna liczbe');
readln(c);
writeln('roznica z sumy 2 pierwszych podanych liczb i ostatniej to ',a+b-c);
end
else writeln('suma podanych liczb to ',a+b);
readln;
end.Plik ZAD2.PAS:
program zad2;
var
a:integer;
begin
writeln('podaj jakas liczbe');
readln(a);

if(a*10)>500 then writeln('podana liczba pomnozona przez 10 jest wieksza od 500 i wynosi ',a*10)

else writeln('podana liczba pomnozona przez 10 jest mniejsza niz 500,  do tej wartosci brakuje ',500-10*a);
readln;
end.Plik ZAD3.PAS:
program zad3;
var
a,b,c,d,e,f,pomoc:integer;

begin
writeln('podaj 3 liczby');
readln(a);
readln(b);
readln(c);
d:=a*a;
e:=b*b;
f:=c*c;
pomoc:=d;

if e<pomoc then pomoc:=e;
if f<pomoc then pomoc:=f;


if pomoc=d then writeln('najmniejszy kwadrat ma pierwasza podana liczba czyli ',a,' a jej kwadrat to ',d);
if pomoc=e then writeln('najmniejszy kwadrat ma druga podana liczba czyli ',b,' a jej kwadrat to ',e);
if pomoc=f then writeln('najmniejszy kwadrat ma trzecia podana liczba czyli ',c,' a jej kwadrat to ',f);

readln;
end.Plik ZAD4.PAS:
program zad4;
var
a,b,c,d,e,pomoc:integer;
begin
writeln('podaj 5 liczb');
readln(a);
readln(b);
readln(c);
readln(d);
readln(e);
pomoc:=a;
if pomoc<b then pomoc:=b;
if pomoc<c then pomoc:=c;
if pomoc<d then pomoc:=d;
if pomoc<e then pomoc:=e;
writeln('najwieksza z podanych liczb to ',pomoc);
readln;
end.Plik ZAD5.PAS:
program zad5;
var
a,b,c:string;

begin
writeln('podaj pierwszy ciag znakow');
readln(a);
writeln('podaj drugi ciag znakow');
readln(b);

if a=b then
begin
c:=a+b;
writeln('ciagi sa identyczne a ich suma zostala zapisana w zmiennej c')
end
else writeln('ciag ',a,' i ',b,' nie sa identyczne');
readln;
Plik zad1.pas:
program multiplication_by_10;
var
liczba:integer;
begin
writeln('podaj liczbe');
readln(liczba);
writeln('liczba ',liczba,' pomnozona przez 10 to ',liczba*10);
readln;
end.Plik zad2.pas:
program age;
var
wiek:integer;
begin
writeln('podaj swoj wiek');
readln(wiek);
writeln('prawdopodobnie zdawales mature ', wiek-19,' lat temu');
readln;
end.Plik zad3.pas:
program subtraction;
var
a,b:integer;
begin
writeln('podaj kolejno 2 liczby potwierdzajac klawiszem ENTER');
readln(a,b);
writeln ('ruznica z odejmowania drugiej podanaj liczby od pierwszej to ', a-b);
readln;
end.Plik zad4.pas:
program addition;
var
C:integer;
begin
writeln('podaj liczbe C');
readln(C);
writeln('C+1=',C+1,';C+3=',C+3,';C+6=',C+6,';C+10=',C+10);
readln;
end. Plik zad5.pas:
program rules;
var
a,b:real;
c:integer;
begin
writeln('podaj 2 liczby potwierdzajac klawiszem ENTER kazda z nich');
readln(a,b);
writeln('====================================================================');
writeln('Co zrobic z wprowadzonymi liczbami??');
writeln(' 1 - odjac pierwsza od drugiej');
writeln(' 2 - odjac druga od pierwszej');
writeln(' 3 - dodac');
writeln(' 4 - pomnozyc');
writeln(' 5 - podzieclic');
write('twoj wybor:');
readln(c);
writeln('====================================================================');
case c of
1: writeln ('wynik z odejmowania pierwszej liczby od drugiej to ',a-b);
2: writeln ('wynik z odejmowania drugiej liczby od pierwszej to ',b-a);
3: writeln ('wynik z dodawania podanych liczb to ',a+b);
4: writeln ('wynik z mnozenia podanych liczb to ',a*b);
5: writeln ('wynik z dzielenia pierwszej podanej liczby przez druga to ',a/b);
else writeln ('chyba cos nie wyszlo...')
end;
readln;
end. Plik zad6.pas:
program ball;
var
r:real;
begin
writeln ('podaj promien kuli');
readln(r);
writeln('zakladam liczbe pi za 3,14');
writeln('pole kuli o podanym promieniu to ',3.14*r*r,'cm kwadratowych');
writeln('natomista jej objetosc to ');
readln;
end.
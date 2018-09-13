Plik zad1.pas:
program zad1;

type
tab=array[1..100] of real;

procedure sort(var B:tab);
var
z,v,w:integer;
x:boolean;
y:real;
begin
w:=0;
v:=0;
repeat
x:=FALSE;
for z:=1 to 99 do
if B[z]>B[z+1] then 
begin
y:=B[z];
B[z]:=B[z+1];
B[z+1]:=y;
x:=TRUE;
inc(w);
end;
inc(v);
until x=FALSE;
writeln('wykonano ',w,' przestawien w ',v,' cyklach');
end;

var
A:tab;
z:byte;

begin
writeln ('losujemy tablice');
randomize;
for z:=1 to 100 do
A[z]:=random;
writeln('wylosowana tablica: ');
for z:=1 to 100 do
write(A[z]:5:2);
writeln;
writeln('uruchamiamy procedure sortujacom');
sort(A);
writeln('posortowana tablica: ');
for z:=1 to 100 do
write(A[z]:5:2);
writeln;
readln;
end.Plik zad2.pas:
program zad2;

type
tosoba = record 
imie: string[20]; 
nazwisko: string[20];
rokurodz: word;
end; 

var
brzydal:tosoba;

begin
randomize;
writeln('pdaj imie');
readln(brzydal.imie);
writeln('pdaj nazwisko');
readln(brzydal.nazwisko);
brzydal.rokurodz:=random(25)+1960;
writeln;
writeln;
writeln('imie: ',brzydal.imie);
writeln('nazwisko: ',brzydal.nazwisko);
writeln('rok urodzenia: ',brzydal.rokurodz);
readln; 

end.Plik zad3.pas:
program zad3;

type
tosoba = record 
naz: string[20]; 
rok, mies, dzien: word;
id: longint;
end; 

procedure pobierz(var A:tosoba);
begin
writeln('podaj nazwisko');
readln(A.naz);
writeln('podaj rok urodzenia');
readln(A.rok);
writeln('podaj miesiac urodzenia');
readln(A.mies);
writeln('podaj dzien urodzenia');
readln(A.dzien);
writeln('podaj numer ID');
readln(A.id);
end;

procedure wyswietl(A:tosoba);
begin
writeln('nazwisko: ',A.naz);
writeln('rok urodzenia: ',A.rok);
writeln('miesiac urodzenia: ',A.mies);
writeln('dzien urodzenia: ',A.dzien);
writeln('numer ID: ',A.id);
readln;
end;

var
B:tosoba;

begin
writeln ('procedura pobierz:');
writeln;
pobierz(B);
writeln;
writeln('procedura wyswietl');
writeln;
wyswietl(B);
readln;
end.Plik zad4.pas:
program zad4;

type 
tosoba = record 
naz: string[20]; 
rok, mies, dzien: word;
id: longint;
end; 
tab=array[1..254] of tosoba;



procedure pobierz2(var A:tab;b:byte);
var
i:byte;
begin
for i:=1 to b do
begin
writeln('podaj nazwisko');
readln(A[i].naz);
writeln('podaj rok urodzenia');
readln(A[i].rok);
writeln('podaj miesiac urodzenia');
readln(A[i].mies);
writeln('podaj dzien urodzenia');
readln(A[i].dzien);
writeln('podaj numer ID');
readln(A[i].id);
end;
end;

procedure wyswietl2(A:tab;b:byte);
var
i:byte;
begin
for i:=1 to b do
begin
writeln('nazwisko: ',A[i].naz);
writeln('rok urodzenia: ',A[i].rok);
writeln('miesiac urodzenia: ',A[i].mies);
writeln('dzien urodzenia: ',A[i].dzien);
writeln('numer ID: ',A[i].id);
end;
readln;

end;

var
X:tab;
q:byte;
begin
writeln('ile pol tablicy chcesz wykozystac? (max 254)');
readln(q);
pobierz2(X,q);
writeln('ile pol wyswietlic?');
readln(q);
wyswietl2(X,q);
readln;
readln;
end.
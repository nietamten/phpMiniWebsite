Plik zad1.pas:
program zad1;
{$APPTYPE CONSOLE}

var
a,b,c:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);
for b:=1 to a do
begin
for c:=1 to b do
write('*');
writeln;
end;
readln;
end.Plik zad2.pas:
program zad2;
{$APPTYPE CONSOLE}

var
a,b,c,d:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);
for b:=a downto 1 do
begin
for c:=1 to b do
write('*');
writeln;
end;
readln;
end.Plik zad3.pas:
program zad3;
{$APPTYPE CONSOLE}

var
a,b,c,d:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);

for b:=0 to a-1 do begin

for c:=a downto b do write (' ');
for d:=1 to b*2+1 do write('*');

writeln;
end;
readln;
end.Plik zad4.pas:
program zad4;
{$APPTYPE CONSOLE}

var
a,b,c,d:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);

for b:=a downto 0 do begin

for c:=a downto b do write (' ');
for d:=1 to b*2+1 do write('*');

writeln;
end;
readln;
end.Plik zad5.pas:
program zad5;
{$APPTYPE CONSOLE}

var
a,b,c,d,e,f:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);
b:= a div 2;


for c:=1 to  b do 
begin
for d:=1 to c do write('*');
writeln;
end;

if (a mod 2)=1 then begin
for d:=1 to b+1 do write('*');
writeln;
end;

for d:=b downto 1 do 
begin
for e:=1 to d do write('*');
writeln;
end;
 



readln;
end.Plik zad6.pas:
program zad6;
{$APPTYPE CONSOLE}

var
a,b,c,d,e,f:byte;
begin
{ TODO -oUser -cConsole Main : Insert code here }

writeln('podaj liczbe od 1 do 15');
readln(a);
b:= a div 2;


for c:=1 to  b do 
begin
for d:=0 to b-c do write(' ');
for d:=1 to c do write('*');
writeln;
end;

if (a mod 2)=1 then begin
for d:=1 to b+1 do write('*');
writeln;
end;

 
for c:=b downto  1 do 
begin
for d:=0 to b-c do write(' ');
for d:=1 to c do write('*');
writeln;
end;


readln;
end.
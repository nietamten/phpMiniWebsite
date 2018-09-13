
/*Napisaæ program, który drukuje na ekranie warto¶æ maksymaln± z liczb 
rzeczywistych podanych jako argument programu (u¿ycie argumentów funkcji main).*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char *argv[])
{ 
  int i;
  float n,min,max;
 
   if (argc>1)
   {
    n=atof(argv[1]);
    min=n;
    max=n;
    for (i=1;i<argc;i++)
    {
        n=atof(argv[i]);
        if (n>max) max=n;
        if (n<min) min=n;
    }
   printf("max: %g\nmin: %g", max , min); 
   }else
   printf("brak argumentow");

  
  getch();
  return 0;
}

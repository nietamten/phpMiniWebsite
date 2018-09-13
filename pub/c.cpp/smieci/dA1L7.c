
/*Wykorzystuj±c funkcje malloc przydzieliæ dynamicznie pamiêæ zmiennym typu 
char, int, long, float, double oraz zapamiêtaæ ich adresy w odpowiednich 
wska¼nikach. W przypadku, gdy alokacja pamiêci powiedzie siê zainicjowaæ 
zmienne danymi wprowadzanymi z klawiatury (np. char *z1 = malloc(sizeof( char)); 
if (z1!=NULL) scanf("%c", z1)). Wyprowadziæ warto¶ci zmiennych na ekran. Przed 
zakoñczeniem programu zwolniæ przydzielon± pamiêæ.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(void)
{ 
  char* a;
  int* b;
  long* c;
  float* d;
  double* e;

//char  
      if ((a = (char *) malloc(sizeof(char))) == NULL)
    {
       printf("Brak miejsca na alokacje zmiennej\n");
       exit(1);  
    }
     else
    {
       printf("Wprowadz wartosc typu char\n");
       scanf("%c",a);
       printf("Wprowadzona wartosc: %c\n",*a);
       free(a);
    }

//int
      if ((b = (int *) malloc(sizeof(int))) == NULL)
    {
       printf("Brak miejsca na alokacje zmiennej\n");
       exit(1);  
    }
     else
    {
       printf("Wprowadz wartosc typu int\n");
       scanf("%d",b);
       printf("Wprowadzona wartosc: %d\n",*b);
       free(b);
    }
    
//long
      if ((c = (long *) malloc(sizeof(long))) == NULL)
    {
       printf("Brak miejsca na alokacje zmiennej\n");
       exit(1);  
    }
     else
    {
       printf("Wprowadz wartosc typu long\n");
       scanf("%d",c);
       printf("Wprowadzona wartosc: %d\n",*c);
       free(c);
    }
    
//float
      if ((d = (float *) malloc(sizeof(float))) == NULL)
    {
       printf("Brak miejsca na alokacje zmiennej\n");
       exit(1);  
    }
     else
    {
       printf("Wprowadz wartosc typu float\n");
       scanf("%f",d);
       printf("Wprowadzona wartosc: %f\n",*d);
       free(d);
    }
    
//double
      if ((e = (double *) malloc(sizeof(double))) == NULL)
    {
       printf("Brak miejsca na alokacje zmiennej\n");
       exit(1);  
    }
     else
    {
       printf("Wprowadz wartosc typu double\n");
       scanf("%lf",e); 
       printf("Wprowadzona wartosc: %lf\n",*e);
       free(e);
    }
  getch();	
  return 0;
}


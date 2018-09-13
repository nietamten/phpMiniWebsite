/*Wprowadzi� z klawiatury rok, miesi�c i dzie�. Je�eli zapis jest poprawny 
(dzie� < 32, miesi�c < 13, stycze� < 32, luty < 30 lub luty < 29, itd.), to
 wyprowadzi� na ekran dat� (miesi�c s�ownie). Uwzgl�dni� lata przest�pne. 
 Przyj��, �e rok nie jest przest�pny je�li: nie dzieli si� przez 4 lub dzieli 
 si� przez 100, ale nie przez 400 (np. lata zwyk�e: 1700, 1800, 2100; lata 
 przest�pne: 4, 1600, 1996, 2000, 2400).
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
int dzien, miesiac, rok;
printf("Podaj date\n"); 
printf("\n\n dzien: ");
scanf("%d",&dzien);
printf("\n miesiac: ");
scanf("%d",&miesiac);
printf("\n rok: ");
scanf("%d",&rok);

switch (miesiac) {
      case 1: if ((dzien>31)^(dzien<1)) return 0; break;
      
      case 2: if ( (rok % 4 == 0) | ((rok % 100 != 0) & (rok % 400 ==0)) )
      {
           if ((dzien>29)^(dzien<1)) return 0;   
      }else
           if ((dzien>28)^(dzien<1)) return 0;
     
      case 3: if ((dzien>31)^(dzien<1)) return 0; break;
      case 4: if ((dzien>30)^(dzien<1)) return 0; break;
      case 5: if ((dzien>31)^(dzien<1)) return 0; break;
      case 6: if ((dzien>30)^(dzien<1)) return 0; break;
      case 7: if ((dzien>31)^(dzien<1)) return 0; break;
      case 8: if ((dzien>31)^(dzien<1)) return 0; break;
      case 9: if ((dzien>30)^(dzien<1)) return 0; break;
      case 10: if ((dzien>31)^(dzien<1)) return 0; break;
      case 11: if ((dzien>30)^(dzien<1)) return 0; break;
      case 12: if ((dzien>31)^(dzien<1)) return 0; break;
       }

printf("\n\npodana data to %d ",dzien," ");
switch (miesiac) {
      case 1: printf("styczen"); break;
      case 2: printf("luty"); break;
      case 3: printf("marzec"); break;
      case 4: printf("kwiecien"); break;
      case 5: printf("maj"); break;
      case 6: printf("czerwiec"); break;
      case 7: printf("lipiec"); break;
      case 8: printf("sierpirn"); break;
      case 9: printf("wrzesien"); break;
      case 10: printf("pazdziernik"); break;
      case 11: printf("listopad"); break;
      case 12: printf("grudzien"); break;
       }
printf(" %d rok ",rok);
   getch();
   return 0;
}
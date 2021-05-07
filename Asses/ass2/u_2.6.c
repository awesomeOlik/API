/*Napíšte program, ktorý po stlačení klávesy F1 vypíše návod na použitie, 
F2 spustí meranie a program skončí F10 alebo ESC. 
Meranie bude spočívať v tom, že program vygeneruje náhodný znak (stačí písmená), 
zobrazí ho do stredu okna a spustí meranie času. Meranie sa zastaví v okamihu, 
keď užívateľ stlačí rovnakú klávesu. Ak užívateľ stlačí niečo iné, program to bude ignorovať. 
Napokon program vypíše zmeraný čas, ktorý uplynie od vypísania po stlačenie rovnakej klávesy.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

int randChar(char *poi)
{
    srand(time(0));
    char ucase[] = "ABCDEAFGHIJKLMNOPQRSTUVWXYZ";
    int d = 0;
    int a = 1;
    int b = 25;
    d = rand()%(b - a + 1) + a;
    
    *poi = ucase[d];  
    return 0;
}

int meranieCasu(char *chr)
{
   clock_t Start, End;
   float Cas;
   int k;
   int i = (int)*chr;
   
   Start = clock();
   do {
     if (kbhit()){
       k = toupper(getch());
       if (k == i){
         End = clock();
         Cas = (float)(End - Start) / CLOCKS_PER_SEC;
         printf("Trvanie: %f s", Cas);
       }
       else if(k == 27){
          return 27;
       } 
       else if(k != i){
         printf("%c - zla klavesa! Skus znova.\n",(char)k) ;    
       }
     }
   } while (k != i);
                              
   return 0;
}           

void program()
{
  int ch;
  char chr;
 
  do {
    if(kbhit()) {                              
      ch = getch();
      if (ch == 0)
        ch = getch();
      switch(ch)                          
        {
          case 59: printf("\n\nPRAVIDLA:\n Po stlaceni klavesy F2 sa vygeneruje pismeno a spusti sa meranie casu, za ktory sa vam podari klavesu stlacit.\n Meranie konci ked stlacite klavesu s odpovedajucim pismenom alebo klavesu ESC.\n\n");
          break;
          case 60: 
            randChar(&chr);
            printf("\nStlac klavesu: %c\n",chr);
            ch = meranieCasu(&chr);
            printf("\n");
          break;   
          default: NULL;           
      }
    }
  } while(ch != 27);

  printf("\nKONIEC MERANIA.\n");
}

int main()
{
  program();
  return 0;
} 
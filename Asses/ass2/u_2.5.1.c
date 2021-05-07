/*Napíšte program, ktorý bude postupne vypisovať čísla od 0 po 50, 
pričom v závislosti od veľkosti čísla sa bude meniť jeho farba, 
napríklad pre čísla od 0 po 10 bude zelená, 11 až 22 červená a 23 až 35 modrá, atď. 
Rýchlosť výpisu na obrazovku obmedzte na cca 1 znak/sekundu.*/

#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
   int pom=0;

   HANDLE hConsole;
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   for(int i=0; i <= 4; i++){
      SetConsoleTextAttribute(hConsole, i + 2);
      if(i==0){
         for (int j=0; j <= 10; j++){
            pom = (10 * i) + j;
            printf("%d\n", pom);
            Sleep(200);
         }    
      }else{
         for (int j=1; j <= 10; j++){
            pom = (10 * i) + j;
            printf("%d\n", pom);
            Sleep(200);
         } 
      }
   } 
   return 0;  
}
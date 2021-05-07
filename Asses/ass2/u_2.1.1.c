/*Vložte do C-programu kúsok assemblerovského kódu, 
ktorým vypočítate súčet dvoch premenných.*/

#include <stdio.h>

static int num1, num2, sum;

int main(int argc, char* argv[])
{
   num1 = 15;
   num2 = 16;
   sum = 0;

   __asm__("mov num1, %eax\n");
   __asm__("add num2, %eax\n");
   __asm__("mov %eax, sum\n");

   printf("num1: %d\nnum2: %d\n\nsum: %d\n",num1,num2,sum);

   return 0;
}
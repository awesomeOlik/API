/*Napíšte pomocou inline asembleru a inštrukcie cpuid program, 
ktorý zistí, aký typ procesora máte v počítači (Intel, AMD, Cyrix,…).*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{ 
  int CPU[3];
  
      __asm__("mov $0x0, %eax\n");
      __asm__("cpuid\n");
      __asm__("mov %%ebx, %0\n":"=r" (CPU[0]));
      __asm__("mov %%edx, %0\n":"=r" (CPU[1]));
      __asm__("mov %%ecx, %0\n":"=r" (CPU[2]));
      
printf("\n%s\n", CPU);
return 0;
}
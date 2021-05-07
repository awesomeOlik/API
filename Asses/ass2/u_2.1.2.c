/*Napíšte pomocou vloženého (embedded) asembleru C-program v ktorom 
použijete vlastnú funkciu na násobenie dvomi bez použitia súčinu.*/

#include<stdio.h>

static int num, sum;

int main(int argc, char* argv[])
{
    num = 15;
    sum = 0;

    __asm__("mov num, %eax\n");
    __asm__("shl %eax\n");
    __asm__("mov %eax, sum\n");

    printf("num = %d\nnum x 2 = %d\n", num, sum);

    return 0;
}
/*Napíšte pomocou vloženého (embedded) asembleru C-program s funkciou na prevod číslice (0 – 15)
 na príslušný ASCII znak predstavujúci hodnotu v hexadecimálnej sústave. Pre čísla 0 – 9 
 bude výstupom znak ‘0’ – ‘9’, pre čísla 10 – 15 znaky ‘A’ – ‘F’.*/

#include<stdio.h>

static int num, sum;

int main(int argc, char* argv[]){

    int i = 0;
    int p = 5;

    i = i + p;

    printf("\nNumber: ");
    scanf("%d", &num);

    asm(".intel_syntax noprefix \n"

        "mov %eax, num\n"
        "cmp %eax, 9\n"
        "jg first\n"
        "mov %ebx, 48\n"
        "add %eax, %ebx\n"
        "jmp last\n"
        "first: mov %ebx, 55\n"
        "add %eax, %ebx\n"
        "last: mov sum, %eax\n"

    ".att_syntax \n");

    printf("\nASCII: %c\n", sum);

    return 0;
}
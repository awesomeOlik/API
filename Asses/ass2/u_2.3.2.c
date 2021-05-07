/*Zaujíma vás, ako to dopadlo v príbehu z úlohy 2.3? Pokračovanie si môžete stiahnuť odtiaľto. 
Aha, že sa nedá prečítať? Musíte ho rozšifrovať. Našťastie je použitá veľmi jednoduchá šifra. 
Na každý znak je aplikovaná operácia logický XOR s číslom 27. 
Napíšte program, ktorý prečíta text zo súboru a každý znak pred výpisom dešifruje.*/

#include<stdio.h>

int main(int argc, char* args[])
{
    FILE *first = fopen("koniec_poviedky.html", "rb");
    FILE *second = fopen("koniec_poviedky_desif.html", "w");
    int ch = 0;

    while((ch = getc(first)) != EOF)
    {
        ch = ch^27;
        putc(ch, second);
    }

    fclose(first);
    fclose(second);

    return 0;
}
/*So súbormi ste už pracovali. Stiahnite a uložte si do súboru tento text poviedky. 
Je napísaný v kódovaní ISO-8859-2, ale aby ste ho vo Windows mohli poriadne prečítať,
 musí byť v kódovaní CP-1250. Našťastie sa tieto dve kódovania líšia len v niekoľkch znakoch. 
 Napíšte program, ktorý text prevedie do správneho kódovania.*/

#include<stdio.h>

int main(int argc, char* argv[])
{
    FILE *first = fopen("poviedka.html", "r");
    FILE *second = fopen("poviedka_desif.html", "w");
    int ch = 0;

    while((ch=fgetc(first)) != EOF)
    {
        switch(ch)
        {
            case 165: 
                ch=188;
                break;
            case 169: 
                ch=138;
                break;
            case 171: 
                ch=141;
                break;
            case 174:
                ch=142;
                break;
            case 181: 
                ch=190;
                break;
            case 185: 
                ch=154;
                break;
            case 187: 
                ch=157;
                break;
            case 190: 
                ch=158;
                break;
            default:
                break;
        }
        fputc(ch, second);
    }
    
    fclose(first);
    fclose(second);

    return 0;
}
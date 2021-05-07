#include <stdio.h>
#include <string.h>

char kont(char c){
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<='F')
        return c-'A'+10;
    else if(c>='a' && c<='f')
        return c-'a'+10;
    else
        return 0;
}

int main(int argc, char* argv[]) {
    int len=0, i=0, sum=0;
    char intHex[1000], str[2];
   
    printf("Zadaj retazec: ");
    scanf("%s", intHex); 
    len=strlen(intHex);

    for(i=1;i<len-2;i+=2) {
        strncpy(str, intHex+i, 2);
        sum=sum+kont(str[0])*16+kont(str[1]);
    }
    printf("Checksum: %X\n", 256-sum%256);

    return 0;
}
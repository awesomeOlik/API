#include<stdio.h>
#include<string.h>

void binar(int pom)
{
	int pocet = 0;
	char ret[50];

	do {
		if (pom % 2 == 0)
			ret[pocet] = '0';
		else
			ret[pocet]='1';
		pom = pom / 2;
		pocet++;
	} while (pom > 0);
	ret[pocet] = '\0';
	printf("V binarnej sustave: %s \n", _strrev(ret));
}

int main(int argc, char* argv[])
{
	char c;
	int i = 33777;
	printf("Zadaj: ");
	scanf("%c", &c);
	printf("ASCII hodnota znaku je %d", c);
	printf("\nDecimalna hodnota pre ASCII znaku %c je %d", c, c);
	printf("\nHexadecimalna hodnota pre ASCII znaku %c je %X\n", c, c);
	binar(c);
	printf("\n\nDecimalna hodnota pre %d je %d ", i, i);
	printf("\nHexadecimalna hodnota pre %d je %X \n", i, i);
	binar(i);
}




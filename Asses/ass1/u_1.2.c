#include<stdio.h>

int main(int argc, char* argv[])
{
	int cis = 0;
	
	while( cis < 1 || cis > 100) 
	{
		printf("Zadaj cislo od 1 do 100: ");
		scanf("%d", &cis);
	}
	
	printf("\nRIMSKE CISLO JE:");
	
	while(cis > 0)
	{
		if(cis == 100){
			printf("C");
			cis = cis - 100;
		}
		else if(cis >= 90){
			printf("XC");
			cis = cis - 90;
		}
		else if(cis >= 50){
			printf("L");
			cis = cis - 50;
		}
		else if(cis >= 40){
			printf("XL");
			cis = cis - 40;
		}
		else if(cis >= 10){
			printf("X");
			cis = cis - 10;
		}
		else if(cis >= 9){
			printf("IX");
			cis = cis - 9;
		}
		else if(cis >= 5){
			printf("V");
			cis = cis - 5;
		}
		else if(cis == 4){
			printf("IV");
			cis = cis - 4;
		}
		else if(cis >= 1){
			printf("I");
			cis--;
		}
	}

	return 0;
}
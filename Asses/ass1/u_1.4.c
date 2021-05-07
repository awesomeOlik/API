#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

double mocnina(double x, int n) {
	int i = 1;
	double ret = x;
	do {
		ret *= x;
		++i;
	} while (i < n);
	return ret;
}

int faktorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * faktorial(n - 1);
}

int main(int argc, char* argv[])
{
	int u=0;
	int i=1;
	printf("Zadaj uhol : ");
	scanf("%d", &u);
	double x = (u*M_PI) / 180;
	double ret = x;

	do {
		if (i % 2 == 0)
			ret = ret + mocnina(x, (i * 2) + 1) / faktorial((i * 2) + 1);
		else
			ret = ret - mocnina(x, (i * 2)+1) / faktorial((i * 2) + 1);
		i += 1;
	} while (mocnina(x, (i * 2) + 1) / faktorial((i * 2) + 1) > 0);
	
	printf("Sinus x = %f\n", ret);
}
